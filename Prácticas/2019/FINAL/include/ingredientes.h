/**
  * @file ingredientes.h
  * @brief Fichero cabecera del TDA Ingredientes
  * 
  */

#ifndef _INGREDIENTES_H_
#define _INGREDIENTES_H_

#include "ingrediente.h"
#include <vector>
using namespace std;

/**
  * @brief T.D.A Ingredientes
  *  
  * Una instancia @e ingredientes del tipo de datos abstracto @c Ingredientes es un objeto
  * que representa un conjunto de ingredientes. A su vez, esta instancia ingredientes se compone
  * de un Vector_Dinamico de Ingredientes. 
  * 
  * Lo representamos como:
  * 
  * datos
  * 
  * Un ejemplo de su uso:
  * @include test_ingredientes.cpp
  * 
  * @author Miguel Ángel Campos Cubillas
  * @date Noviembre 2019 
  */ 

class Ingredientes{
private:
/**
  * @page repIngredientes Rep del TDA Ingredientes
  * 
  * @section invIngredientes Invariante de la representación
  * 
  * El invariante es \e Vector_Dinamico de ingredientes llamado datos válido
  * 
  * @section faIngredientes Función de abstracción
  * 
  * Un objeto válido @e rep del TDA Ingredientes representa al valor
  * 
  * {datos}
  */

    vector<Ingrediente> datos; /**< datos */
    vector<int> indice_tipo;

public:
    /**
      * @brief Constructor por defecto de la clase. Crea el conjunto de ingredientes vacío.
      */
    Ingredientes();
    /**
      * @brief insertarIngrediente
      * @param ingrediente Ingrediente a insertar
      * @return Inserta en el objeto implícito el Ingrediente
      */
    void insertarIngrediente(const Ingrediente &ingrediente);

    /**
      * @brief borrarIngrediente
      * @param nroIngrediente posición del Ingrediente a borrar
      * @return Borra el Ingrediente de la posición nroIngrediente del objeto implícito 
      */
    void borrarIngrediente(const int nroIngrediente);

    /**
      * @brief borraIngredienteXNombre
      * @param nombre del Ingrediente a borrar
      * @return Borra el Ingrediente del conjunto cuyo nombre coincide con el parámetro
      */
    void borrarIngredienteXNombre(const string &nombre);

    /**
      * @brief modificaIngrediente
      * @param i posición del Ingrediente a modificar
      * @param ingrediente Ingrediente para modificar
      * @return Modifica el Ingrediente de la posición i por el "ingrediente" 
      */ 
    void modificaIngrediente(const int i, const Ingrediente &ingrediente);

    /**
      * @brief getIngrediente
      * @param i posición del Ingrediente
      * @return Devuelve el Ingrediente de la posición i
      * @pre i debe de ser un valor válido
      */
    Ingrediente getIngrediente(const int i);

    /**
      * @brief get
      * @param nombre nombre del ingrediente
      * @return Devuelve el Ingrediente cuyo nombre es equivalente al parametro
      * @pre nombre debe de ser un nombre válido
      */
    Ingrediente get(const string &nombre);

    /**
      * @brief getNumIngredientes
      * @return Devuelve el número de ingredientes del conjunto
      */
    const int getNumIngredientes() const;

    /**
      * @brief getInformación
      * @param nombre nombre del ingrediente
      * @return Devuelve la nformación del ingrediente cuyo nombre es equivalente al parametro
      */
    string getInformacion(const string nombre);

    /**
      * @brief getTipos
      * @return Devuelve un Vector_Dinamico de tipo string con los tipos de los ingredientes del conjunto
      */
    vector<string> getTipos();
    
    /**
      * @brief getIngredientesTipos
      * @param tipo tipo de los ingredientes a buscar
      * @return Ingredientes cuyo tipo coincide con el parametro tipo
      * @pre tipo existente
      */
    Ingredientes getIngredientesTipo(const string tipo);

    /**
      * @brief Sorbrecarga del operador[]
      * @param i entero que indica una posicion
      * @return Ingrediente de la posicion i 
      */
    Ingrediente &operator[](const int i);

    /**
      * @brief Sorbrecarga constante del operador[]
      * @param i entero que indica una posicion
      * @return Ingrediente de la posicion i 
      */
    const Ingrediente &operator[](const int i) const;

    /**
      * @brief ordenaPorNombre
      * @return ordena los Ingredientes por orden alfabético 
      */
    void ordenaPorNombre();

    /**
      * @brief ordenaPorTipo
      * @return ordena los Ingredientes por tipo y los devuelve en un objeto de tipo Ingredientes
      */
    void ordenaPorTipo();

    /**
      * @brief ordenaPorTipo
      * @return ordena los Ingredientes del objeto implícito en otra instancia de Ingredientes
      *         por tipo y la imprime 
      */
    void imprimirPorTipo(ostream &os);

    /**
      * @brief getEstadistica
      * @return calcula datos estadísticos acerca del conjunto de Ingredientes del tipo
      *         indicado por el string tipo          
      */
    void getEstadistica(const string tipo);

    Ingrediente getIngrediente(const string nombre);

    /**
      * @brief Salida de Ingredientes a ostream
      * @param os stream de salida
      * @param ingredientes Ingredientes a escribir
      * @post Se obtiene en \a os los ingredientes  con \e ingrediente los ingredientes del conjunto
      */
    friend ostream &operator<<(ostream &os, const Ingredientes &ingredientes);

    /**
      * @brief Entrada de Ingredientes a istream
      * @param is stream de entrada
      * @param ingredientes Ingredientes que reciben los ingredientes
      * @retval Los ingredientes leidos en ingredientes
      * @pre La entrada tiene el formato ingredientes con \e ingrediente
      */
    friend istream &operator>>(istream &is, Ingredientes &ingredientes);


    int * obtenerDatosCalorias();

    int * obtenerDatosHc();

    int * obtenerDatosProteinas();

    int * obtenerDatosGrasas();

    int * obtenerDatosFibras();

    float obtener_promedio(int *datos);

    float obtener_varianza(int *datos);

    float obtener_desviacion(float varianza, int *datos);

    void obtener_desviaciones();

    void getEstadistico();


    /**
      * @brief Clase para iterar sobre los ingredientes 
      */
    class iterator{
      private:
        vector<Ingrediente>::iterator it;
      public:

        iterator & operator++(){
          ++it;
          return *this;
        }

        iterator & operator--(){
          --it;
          return *this;
        }

        Ingrediente & operator*(){
          return (*it);
        }

        bool operator==(const iterator &i){
          return i.it == it;
        }

        bool operator!=(const iterator &i){
          return i.it != it;
        }

        iterator & operator=(const iterator &i){
          it = i.it;
          return *this;
        }

        friend class Ingredientes;
    };

    /**
      * @brief Clase para iterar sobre los ingredientes (modo const)
      */
    class const_iterator{
      private:
        vector<Ingrediente>::const_iterator it;
      public:

        const_iterator & operator++(){
          ++it;
          return *this;
        }

        const_iterator & operator--(){
          --it;
          return *this;
        }

        const Ingrediente & operator*() const{
          return (*it);
        }

        bool operator==(const const_iterator &i) const{
          return i.it == it;
        }

        bool operator!=(const const_iterator &i) const{
          return i.it != it;
        }

        const_iterator & operator=(const const_iterator &i){
          it = i.it;
          return *this;
        }

        friend class Ingredientes;

    };

    /**
      * @brief Inicializa un iterator al comienzo de Ingredientes
      */
    iterator begin(){
      iterator i;
      i.it = datos.begin();
      return i;
    }

    /**
      * @brief Inicializa un iterator al final de Ingredientes
      */
    iterator end(){
      iterator i;
      i.it = datos.end();
      return i;
    }

    /**
      * @brief Inicializa un const_iterator al comienzo de Ingredientes
      */  
    const_iterator begin()const{
      const_iterator i;
      i.it = datos.begin();
      return i;
    }
    
    /**
      * @brief Inicializa un const_iterator al final de Ingredientes
      */
    const_iterator end()const{
      const_iterator i;
      i.it = datos.end();
      return i;
    }

};

#endif