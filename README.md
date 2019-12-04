# bibliotheque

## Current problem : 

On nous dit dans le sujet de pointer les data type nom de l'auteur, titre, année de publication, code ISBN avec un pointeur _void_. Souci, à l'initialisation de celui-ci, impossible de stocker la valeur de l'attribut car problème de type (void = pas de type, donc peut pas stocker). Il faut essayer de forcer le type à revenir, mais comment? On a passé le type en attribut (QVariant::String/QVariant::Int), il faudrait pouvoir le récupérer pour pouvoir lire le pointeur, et ça c'est un GROS PROBLÈME DEPUIS 24H JPP.
