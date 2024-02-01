# Devoir sur la génération d'une clé pour coder et décoder un message :

**Pour compiler le programme :**

`gcc -o vernam vernam.c`

**Conseils d'utilisation**

Faire `./vernam` seul permet de voir comment utiliser le programme, quels arguments rentrer sur la ligne de commandes et de lancer le programme.

Les fichiers `<fichier_clé>`, `<fichier_msg_codé>` et `<fichier_msg_décodé>` seront générés au cours de l'exécution de programme, ils ne sont donc pas présents sur la page git de celui-ci.

D'abord, lancer le code avec l'option permettant de générer une clé : l'option `-k`

Une fois la clé générée, coder le message original avec l'option `-c`, à l'aide de `<ficher_msg>` et de `<fichier_clé>`. Le message codé sera placé dans `<fichier_msg_codé>`.

Pour finir, décoder le message codé avec l'option `-d`, à l'aide de `<fichier_msg_codé>` et de `<fichier_clé>`. Le message décodé sera placé dans `<fichier_msg_décodé>`.

**Pour lancer le programme :**
- `./vernam -k <fichier_msg> <fichier_clé>` -> Génère une clé de cryptage en fonction du message présent dans `<fichier_msg>` et stocke la clé dans `<fichier_clé>`.
- `./vernam -c <fichier_msg> <fichier_clé> <fichier_msg_codé>` -> Génère un message codé à partir du message présent dans `<fichier_msg>` et de la clé présente dans `<fichier_clé>` et stocke le message codé dans `<fichier_msg_codé>`.
- `./vernam -d <fichier_msg_codé> <fichier_clé> <fichier_msg_decodé>` -> Génère un message décodé à partir du message présent dans `<fichier_msg_codé>` et de la clé présente dans `<fichier_clé>` et stocke le message décodé dans `<fichier_msg_décodé>`.

**Limites de mon programme :** 

Pour que l'algorithme de cryptage fonctionne, la taille de la clé doit être supérieure ou égale à celle du message. Cela n'est pas pratique lorsque l'on doit crypter de grands messages car on doit transmettre une clé qui fait la même taille que le message pour son décodage. Le programme a été testé avec un texte `"lorem ipsum"` de 500 mots et je n'ai pas rencontré de ralentissements significatifs lors du codage et du décodage du message. Le temps de calcul a été instantané, le fichier contenant le message décodé `<fichier_msg_décodé>` est généré d'un coup.