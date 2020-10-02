#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

#endif // VALIDATIONS_H_INCLUDED

/** \brief Validates if a string contains only letters
 *
 * \param char str[]
 * \return int Return (-1) if Error [the is one or more char that aren't letters] - (0) if Ok
 *
 */
int charOnly(char str[]);

/** \brief It validates the input of an integer option
 *
 * \param int* pResult pointer to result
 * \param char* errorMsj
 * \param int min the minumun option
 * \param int max the maximum option
 * \return int Return (-1) if Error [Invalid length or NULL pointer or minumun is larger than maximun] - (0) if Ok
 *
 */
int getOption(int* pResult, char* errorMsj, int min, int max);

/** \brief Puts a name in good condition
 *
 * \param char* Name pointer to string
 *
 */
void orderName(char* name);
