from flask import Flask, request, jsonify
from datetime import datetime
import json

count = 0  #Compteur des clients manquants

client = {"temperature" : None, "pression" : None, "qualite" : None, "temps" : None, "ip" : None, "mac" : None}   #Dictionnaire qui contient les valeurs d'un client
itteration = [] # Dictionnaire qui sera l'itération d'un tableau
Body = []   # Tableau qui contiendra toute les données
Item = {"items":Body}   # Dictionnaire qui représente l'ensemble de l'API
# ------------------------------------------
listIp = []     # Tableau qui contient la liste de tous les clients
lastClients = []    # Tableau qui contiendra maximum 3 clients. 

# ------------------------------------------

app = Flask(__name__)  # Création de l'application
@app.route('/recuperer_infos', methods=['POST']) # Définition de la route commune à tous

def recuperer_infos(): # Fonction qui récupère les informations

    if request.method == 'POST':
        global lastClients, count, listIp, client, Body, itteration, Item; # On déclare les variables en global pour pouvoir les utiliser dans la fonction
        data = request.get_json()   # Récupération de ce qui est envoyée
        maintenant = datetime.now() # Récupère l'heure actuelle de réception
        temps = maintenant.strftime("%Y-%m-%d %H:%M:%S")    # Formate l'heure
        
        # Traitons la données reçu
        temperature = data.get("temperature")
        pression = data.get("pression")
        qualite = data.get("qualite")
        ip = data.get("ip")
        mac = data.get("mac")
        
        # Si on ne reçoit pas de nouvelle IP
        if ip in listIp: # On vérifie dans la liste des 3 derniers clients s'il est dedans
            if ip in lastClients: #  si Oui, on augmente le compteur
                count += 1
        
            else: # Sinon on ajoute l'ip dans la liste
                lastClients.append(ip)

                # On donne les valeurs au dictionnaire
                client["temperature"] = temperature
                client["pression"] = pression
                client["qualite"] = qualite
                client["ip"] = ip
                client["mac"] = mac
                client["temps"] = temps # On donne l'heure actuelle

                # On rajoute le client dans le tableau ittération qui lui aussi attend 3, élément
                itteration.append(client)

                # On vide le dico
                client = {"temperature" : None, "pression" : None, "qualite" : None, "temps" : None, "ip" : None}

        # Si on a une nouvelle ip
        else: # On vérifie s'il est dans la liste des derniers clients
            if ip in lastClients:
                count += 1 # On augmente le compteur
        
            else:  # S'il n'est pas dans la liste des derniers clients

                #On ajoute l'ip dans la liste
                lastClients.append(ip)

                # On rempli le dico
                client["temperature"] = temperature
                client["pression"] = pression
                client["qualite"] = qualite
                client["temps"] = temps 
                client["ip"] = ip
                client["mac"] = mac

                # On met le dico dans l'itteration
                itteration.append(client)

                # On vide le dico
                client = {"temperature" : None, "pression" : None, "qualite" : None, "temps" : None, "ip" : None, "mac" : None}

            #On ajoute l'ip à la liste
            listIp.append(ip)
            
        # Si la liste des derniers clients vaut 3, ou que le compteur est supérieur ou égal à 10
        if len(lastClients) == 4 or count >= 10:
            
            # On ajoute l'itteration dans le Body
            Body.append(itteration)
            # On ajoute l'itteration dans le dico
            Item = {"items":Body}

            #On créé le fichier
            with open("data-test-18.json", "w") as f: 
                Item_dump = json.dumps(Item) # On convertit le dico en json
                f.write(str(Item_dump)) # On écrit dans le fichier
                f.write("\n") 

            #On vide tous
            client = {"temperature" : None, "pression" : None, "qualite" : None, "temps" : None, "ip" : None, "mac" : None}
            lastClients = []
            itteration = []
            count = 0
            Item = {"items":Body}
        
        return "Données reçues avec succès", 200 # On renvoie un message de succès


if __name__ == '__main__': # On lance l'application
    app.run(host='10.1.6.106',port=8080)