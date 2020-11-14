#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

/** \brief Recorre una lista de test para linked list y los va ejecutando
 *
 * \param int test numero de test
 *
 */
void validations_testLL(int test);

/** \brief Valida un input de una opcion con un numero entero
 *
 * \param int* pResult puntero a resultado
 * \param char* errorMsj mensaje de error
 * \param int min minimo
 * \param int max maximo
 * \return int Retorna (-1) si hay Error [Tamaño invalido, puntero
 *  NULL o minimo mayor que maximo] - (0) si esta todo Ok
 *
 */
int validations_getOption(int* pResult, char* errorMsj, int min, int max);

/** \brief Valida que un string solo tenga caracteres alfabeticos
 *
 * \param char str[]
 * \return int Retorna (-1) para error [uno o mas caracteres no alfabeticos]
 * - (0) si esta todo Ok
 *
 */
 int validations_charOnly(char* str);

 /** \brief Valida que un nombre tenga formato correcto
 *
 * \param char* name
 * \return Retorna FALSE (0) si hay errores, TRUE(1) Si esta todo OK.
 *
 */
 int validations_isValidName(char* nombre);

 /** \brief Valida que un literal de cadena sea un entero.
 *
 * \param Char str
 * \return Retorna FALSE (0) si hay errores, TRUE(1) Si esta todo OK.
 *
 */
 int validations_isValidNumber(char* str);

 /** \brief Otorga formato a un nombre
 *
 * \param char* Str string a formatear
 *
 */
 void formatStr(char* str);

 int validations_isValidType(char* type);
 int validations_isValidSex(char sex);
 int validations_isValidEdad(int edad);

#endif // VALIDATIONS_H_INCLUDED
