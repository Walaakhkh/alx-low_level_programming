#!/usr/bin/python3
def safe_print_list(my_list=[], x=0):
    count = 0
    try:
        while count < x:
            print(my_list[count], end='')
            count += 1
    except IndexError:
        pass
    print('')
    return count

# Testing the function as per your example

my_list = [1, 2, 3, 4, 5]

nb_print = safe_print_list(my_list, 2)
print("nb_print: {:d}".format(nb_print))

nb_print = safe_print_list(my_list, 5)
print("nb_print: {:d}".format(nb_print))

nb_print = safe_print_list(my_list, 7)
print("nb_print: {:d}".format(nb_print))
