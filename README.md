### CURRENT SITUTATION
  
On sait créér une base de données avec le code, l'ouvrir et autre.
  
On choisit de travailler de la manière suivante : chaque bibliothèque est stockée dans une base de données différente. Les livres sont rangés dans la table "livre" de la base de données de la bibliothèque (plus ou moins imposé par le sujet).
  
Le code permet de générer une IHM semblable à celle mentionnée dans le sujet. 
  
La base de toutes les fonctions à réaliser est codée (les fonctions sont créées mais vides, aka ouvrirBibliotheque() ou autres, l'implémentation ne doit pas être trop compliquée).
  
Les classes persistentAttribute et persistentObject sont utilisables (aka on peut créér un livre, mettre un auteur, un titre, un ISBN et une année de publication dedans, sans problème de typage ou autre : comment on fait ça ? Etape 1 = on créé un objet persistent que l'on nomme livre, puis on ajoute 4 attributs persistants auteur titre ISBN annee dans la liste de ses attributs privés).
  
  
  
### NEXT STEPS
  
#### Dans QT:
  
Bibliothèque = QList de livres
  
Livre = objet persistant constitué d'un auteur, d'un titre, d'un code isbn, d'une année de publication (attributs)
  
Attribut = attibut persistant
  

#### Dans la base de données:
  
Bibliothèque = base de donnée
  
Livre = ligne de la base de donnée, rangée dans la table "livre"
  
Attribut = élément d'une ligne d'une colonne (un auteur est dans la colonne "auteur" blablabla)
    
  
### FURTHER DOC ON MY WORK
  
[https://docs.google.com/document/d/1cSQm-nuM7-uKdMx5zj5Wh4WcNE8H0voZ92d3664rXyk/edit?usp=sharing]
