from flask import Flask, request, jsonify
from datetime import datetime
import json

itteration = {} # Dictionnaire qui sera l'itération d'un tableau
Body = []   # Tableau qui contiendra toute les données
Item = {"items":Body}   # Dictionnaire qui représente l'ensemble de l'API

memoire = {"temperature": None, "humidite": None}

app = Flask(__name__)
@app.route('/recuperer_infos', methods=['POST'])
def recuperer_infos():
    if request.method == 'POST':
        data = request.get_json()   # Récupération de ce qui est envoyée
        maintenant = datetime.now() # Récupère l'heure
        temps = maintenant.strftime("%Y-%m-%d %H:%M:%S")    # Formate l'heure

        # Traitons la données reçut
        temperature = data.get("temperature")
        humidite = data.get("humidite")
        
        # Si la température est différent de None ou humidité alors on le met dans un tableau
        if temperature != None:
            memoire["temperature"] = temperature
            
        if humidite != None:
            memoire["humidite"] = humidite

        if memoire["temperature"] != None and memoire["humidite"] != None:
            itteration = {"humidite" : memoire["humidite"], "temperature" : memoire["temperature"], "temps" : temps}
            Body.append(itteration)
            Item = {"items":Body}
            with open("data-test-4.json", "w") as f:
                Item_dump = json.dumps(Item)
                f.write(str(Item_dump))
                f.write("\n")
            memoire["temperature"] = None
            memoire["humidite"] = None
        
        return "Données reçues avec succès", 200


if __name__ == '__main__':
    app.run(host='10.1.6.105',port=8080)
