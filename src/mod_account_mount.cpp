#include "Config.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "Player.h"
#include <sstream>
#include <string>

class AccountMounts : public PlayerScript
{
    static const bool limitrace = true; // This set to true will only learn mounts from chars on the same team, do what you want.

    // Define a list of SpellIDs in config file to exclude from being learned account-wide.
    std::set<uint32> excludedSpellIds;

public:
    AccountMounts() : PlayerScript("AccountMounts") 
    {
        // Load excluded spell IDs from config
        std::string excludedSpellsStr = sConfigMgr->GetStringDefault("Account.Mounts.ExcludedSpellIDs", "");
        std::istringstream spellStream(excludedSpellsStr);
        std::string spellIdStr;
        while (std::getline(spellStream, spellIdStr, ',')) {
            uint32 spellId = std::stoul(spellIdStr);
            excludedSpellIds.insert(spellId);
        }
    }
    
    void OnLogin(Player* pPlayer)
    {
        if (sConfigMgr->GetOption<bool>("Account.Mounts.Enable", true))
        {
            if (sConfigMgr->GetOption<bool>("Account.Mounts.Announce", false))
            {
                ChatHandler(pPlayer->GetSession()).SendSysMessage("This server is running the |cff4CFF00AccountMounts |rmodule.");
            }

            std::vector<uint32> Guids;
            uint32 playerAccountID = pPlayer->GetSession()->GetAccountId();
            QueryResult result1 = CharacterDatabase.Query("SELECT `guid`, `race` FROM `characters` WHERE `account`={};", playerAccountID);

            if (!result1)
                return;

            do
            {
                Field* fields = result1->Fetch();
                uint32 race = fields[1].Get<uint8>();

                if ((Player::TeamIdForRace(race) == Player::TeamIdForRace(pPlayer->getRace())) || !limitrace)
                    Guids.push_back(fields[0].Get<uint32>());

            } while (result1->NextRow());

            std::vector<uint32> Spells;

            for (auto& i : Guids)
            {
                QueryResult result2 = CharacterDatabase.Query("SELECT `spell` FROM `character_spell` WHERE `guid`={};", i);
                if (!result2)
                    continue;

                do
                {
                    Spells.push_back(result2->Fetch()[0].Get<uint32>());
                } while (result2->NextRow());
            }

            for (auto& i : Spells)
            {
                // Check if the spell is in the excluded list before learning it
                if (excludedSpellIds.find(i) == excludedSpellIds.end())
                {
                    auto sSpell = sSpellStore.LookupEntry(i);
                    if (sSpell->Effect[0] == SPELL_EFFECT_APPLY_AURA && sSpell->EffectApplyAuraName[0] == SPELL_AURA_MOUNTED)
                        pPlayer->learnSpell(sSpell->Id);
                }
            }
        }
    }
};

void AddAccountMountsScripts()
{
    new AccountMounts();
}
