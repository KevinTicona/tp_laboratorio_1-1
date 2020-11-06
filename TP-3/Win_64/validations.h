#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

/** \brief It validates the input of an integer option
 *
 * \param int* pResult pointer to result
 * \param char* errorMsj
 * \param int min the minumun option
 * \param int max the maximum option
 * \return int Return (-1) if Error [Invalid length or NULL pointer or minumun is larger than maximun] - (0) if Ok
 *
 */
int validations_getOption(int* pResult, char* errorMsj, int min, int max);

/** \brief Validates if a string contains only letters
 *
 * \param char str[]
 * \return int Return (-1) if Error [the is one or more char that aren't letters] - (0) if Ok
 *
 */
int validations_charOnly(char* str);

/** \brief Validates if a name is ok
 *
 * \param char* name
 * \return int Return (0 false) if Error [if the name is not valid] - (1 true) if Ok
 *
 */
int validations_nombre(char* nombre);

/** \brief Validate if the number of hours is correct
 *
 * \param int horasTrabajadas
 * \return int Return (0 false) if Error [if the name is not valid] - (1 true) if Ok
 *
 */
int validations_horasTrabajadas(int horasTrabajadas);

/** \brief Validate if the salary is correct
 *
 * \param int horasTrabajadas
 * \return int Return (0 false) if Error [if the name is not valid] - (1 true) if Ok
 *
 */
int validations_sueldo(int sueldo);

/** \brief Valida que un literal de cadena sea un entero.
 *
 * \param Char str
 * \return int Return (0 false) if Error [if the name is not valid] - (1 true) if Ok
 *
 */
int validations_numeroValido(char* str);

#endif // VALIDATIONS_H_INCLUDED
