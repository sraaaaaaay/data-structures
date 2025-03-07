#ifndef COMPARE_H
#define COMPARE_H

/**
 * @brief Callback comparator for two strings
 * 
 * @param lhs First string
 * @param rhs Second string
 * @return int 0 if equal, otherwise 1
 */
int compare_strings(const void* lhs, const void* rhs);

/**
 * @brief Callback comparator for two integers
 * 
 * @param lhs First integer
 * @param rhs Second integer
 * @return int 0 if equal, positive if lhs > rhs, negative if rhs > lhs
 */
int compare_ints(const void* lhs, const void* rhs);

/**
 * @brief Generic callback comparator (structs etc)
 * 
 * @param lhs First operand
 * @param rhs Second operand
 * @param size Number of bytes to compare (usually list->element_size)
 * @return int 
 */
int compare(const void* lhs, const void* rhs, size_t size);

#endif