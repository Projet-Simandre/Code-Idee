from flask import Flask, request, jsonify
from datetime import datetime
import json
   

app = Flask(__name__)

general =[]
biggeneral = {"items":general}

@app.route('/recuperer_infos', methods=['POST'])
def recuperer_infos():
    if request.method == 'POST':
        data = request.get_json()
        general.append(data)
        biggeneral = {"items":general}
        # Traitez les données reçues ici
        # Enregistrez les données dans un fichier .txt, par exemple
        with open("donn.json", "w") as f:
            biggeneral_dump = json.dumps(biggeneral)
            f.write(str(biggeneral_dump))
            f.write("\n")
        return "Données reçues avec succès", 200

if __name__ == '__main__':
    app.run(host='10.1.6.105',port=8080)
