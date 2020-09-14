#ifndef ACUNAUTN_H_INCLUDED
#define ACUNAUTN_H_INCLUDED

#endif // ACUNAUTN_H_INCLUDED


/** \brief Solicita una opcion numerica al usuario, valida, verifica y devuelve el resultado.
 *
 * \param pResultado se guarda el numero ingresado por el usuario.
 * \param mensajeError mensaje de error si hay un error.
 * \param minimo valor aceptado.
 * \param maximo valor aceptado.
 * \return Exitoso = 0. Error = -1.
 *
 */
int getOption(int* pResultado, char* mensajeError, int minimo, int maximo);


/** \brief Imprime el menu con los datos que se van ingresando.
 *
 * \param Bandera 1: valida si operando1 tiene valor ingresado.
 * \param Bandera 2: valida si operando2 tiene valor ingresado.
 * \param Primer operador.
 * \param Segundo operador.
 * \return 0.
 *
 */
int menu(int b1, int b2, int operando1, int operando2);


/** \brief Muestra los resultados de las operaciones.
 *
 * \param Bandera que indica que la opción calcular fue seleccionada previamente.
 * \param Primer operador.
 * \param Segundo operador.
 * \return Reset para setear las banderas a 0 nuevamente.
 *
 */
int mostarResultado(int bandera, int operando1, int operando2);


/** \brief Solicita al usuario el ingreso de un numero y lo guarda.
 *
 * \return Numero.
 *
 */
int obtNum();


/** \brief Suma dos numeros.
 *
 * \param Primer operador.
 * \param Segundo operador.
 * \return Resultado de la suma de los dos operadores.
 *
 */
int suma(int a, int b);


/** \brief Resta dos numeros.
 *
 * \param Primer operador.
 * \param Segundo operador.
 * \return Resultado de la resta de los dos operadores.
 *
 */
int resta(int a, int b);


/** \brief Multiplica dos numeros.
 *
 * \param Primer operador.
 * \param Segundo operador.
 * \return Resultado de la multiplicación de los dos operadores.
 *
 */
long long int multiplicacion(int a, int b);


/** \brief Calcula el factorial de un entero.
 *
 * \param Numero entero.
 * \return Resultado del factorial de ese numero entero.
 *
 */
long long int factorial(int a);


/** \brief Divide dos numeros.
 *
 * \param Puntero a resultado para guardar el resultado si es valido o devolver un error si se quiere dividir por cero.
 * \param Primer operador.
 * \param Segundo operador.
 * \return Resultado de la división de los dos operadores.
 *
 */
int division(float* pResultado, int a, int b);
