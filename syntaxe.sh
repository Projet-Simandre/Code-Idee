#!/bin/bash
jq '.valeur |= gsub("'"; "")' donne.json 
