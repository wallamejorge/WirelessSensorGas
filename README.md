WirlessSensorGas
================


------------------------------------------------------------------------------------

Intro

------------------------------------------------------------------------------------

Sensor Inamabrico distribuido con un server central para la medición de multiples gases implementado en una tarjeta de desarrollo embebido (BeagleBone Black).El proyecto esta orientado a la medición de metano y CO para ganado en un proyecto de investigación ambiental. Dadas las condiciones del terreno (extensión) y la cantidad de animales requeridos , se hace tediosa la metodologia tradicional de medicion usando tecnicas de caracterización de gases. Por esta razón se propone utilizar una solución electronica usando una tarjeta de desarrollo , comunicación inalambrica para procesar los datos en un server centralizado de manera automatica de manera que los investigadores se aproximen a los animales lo menos posible.






------------------------------------------------------------------------------------

Index

------------------------------------------------------------------------------------

  *Folders:

      **backup:Se guarda un backup de la wiki temporal y de los tutoriales, manuales,etc.
  
      **docs:Se almacenan los manuales de las librerias, PCB, prototipos,etc.
  
      **html:Se almacena el portal HTML que tiene como server Dropbox ( temporalmente)
  
      **rtl:Se almacenan recursos como drivers, instaladores, scripts, etc.
    
      **scr:Se almacena el codigo fuente en tres carpetas c,python  y latex.
  
      **wiki:Se almacenan imagenes, documentos, guias, videos, todo el material para la wiki
  
  *Files:

       **LICENSE: Archivo de licencia apache sobre lo producido en el grupo
  
       **README: Archivo con informacion sobre el proyecto (Este archivo)
  
       **ABSTRAC: Resumen de los objetivos, metodologia, motivacion, soluciones, etc.
       
  
------------------------------------------------------------------------------------

Setting Up WirelessSensorGas

------------------------------------------------------------------------------------

        *makefile: El makefile encontrado en el directorio home , ejecuta todos los comandos necesarios
        para el proyecto, por ejemplo:
        
            **cpysrc : se ejecuta desde la PC en el directorio raiz 
                       y se copiara el contenido de src en la BeagleBone
             
            **cpyrtl : Se ejecuta desde la PC en el directorio raiz
                       y se copiara el contenido de rtl en la BeagleBone
                       
             **git   : Se ejecuta desde la PC en el directorio raiz y
                       actualizara el contenido del git (necesita tener autoriado
                       previamente user y password )







