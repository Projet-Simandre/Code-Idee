from flask import Flask, request, jsonify
from datetime import datetime


def recallTemp():
    

app = Flask(__name__)

@app.route('/recuperer_infos', methods=['POST'])
def recuperer_infos():
    if request.method == 'POST':
        data = request.get_json()
        # Traitez les données reçues ici
        # Enregistrez les données dans un fichier .txt, par exemple
        with open("donnees.json", "a") as f:
            f.write(str(data))
        return "Données reçues avec succès", 200
        
if __name__ == '__main__':
    app.run(host='10.1.6.105', port=8080)
