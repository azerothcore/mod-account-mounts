# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

[Ingles](README.md) | [Español](README_ES.md)

## mod-account-mounts

El modulo, tiene como objetivo, recorrer la lista de personajes de una cuenta (lo cual se acciona cuando el jugador ingresa al servidor, con el OnLogin), obtener los playerGuids y almacenar las spells de monturas que todos los personajes conocen. Luego, se recorre dicha lista, y se le enseña al personaje que no conoce el spell, dicho spell. Por defecto, enseña las monturas que son de la misma raza, sin embargo, se puede habilitar para que se enseñe todas, independientemente de la faccion.

Actualmente, se encuentra en desarrollo otro modulo, el cual no esta terminado, pero que tiene una idea similar, sin embargo, la diferencia, es que almancena las spells en una base de datos, permitiendo clasificarlas en Alianza, horda y neutrales, por lo que si un jugador es alianza, aprende las de la alianza mas las neutrales. Y si un jugador es Horda, aprende las de dicha faccion mas les neutrales. Como es el caso, de la montura del rey exanime.

https://github.com/pangolp/mod-mounts-on-account

- Estado de compilación más reciente con azerothcore:

[![Build Status](https://github.com/azerothcore/mod-account-mounts/workflows/core-build/badge.svg?branch=master&event=push)](https://github.com/azerothcore/mod-account-mounts)

Créditos: ConanHun513
