# CSCI 1913, Spring 2021, Project 1
# Student Names:
# Samuel Capece

import random

RIGHT = (1, 0)
DOWN = (0, 1)
RIGHT_DOWN = (1, 1)
RIGHT_UP = (1, -1)
DIRECTIONS = (RIGHT, DOWN, RIGHT_DOWN, RIGHT_UP)


def get_size(grid):
    """ Takes the length of the grid to find the height (ie number of rows) and the length of a single row
    to find the width. Returns a tuple with sizes."""

    height = len(grid)
    width = len(grid[0])
    size = [width, height]
    return tuple(size)


def print_word_grid(grid):
    """ Uses a for loop to print each row of a grid, inside the for loop is the * loop which prints each element
    in the row and uses the sep operator to change the space from the default of one space to zero spaces"""

    for i in range(0, len(grid)):
        print(*grid[i], sep='')


def copy_word_grid(grid):
    """ creates a new grid called copy and loops over the original grid to create new rows for the copy. Then
    uses a nested for loop to access the nested list of strings in the original grid and appends these strings
     to the copied rows. Ends up with original list copied exactly. Returns copied list"""

    copy = []
    for row in grid:
        copy_row = []
        for string in row:
            copy_row.append(string)
        copy.append(copy_row)
    return copy


def extract(grid, position, direction, max_len):
    """Checks if the length is above zero with an if statement else returns an empty string.
     Sets the position to two variables x and y, creates
     a list and a string with the first digit of the solution. Uses a for loop to continually change x and y using the
     direction for the duration of the max length. Checks that x and y are above zero and then appends the string
     in the new grid location to the solution list and string. Uses an error exception in case the user puts a number
     above the size (as this number wouldn't be added to the list anyway). Returns the string solution"""

    if max_len > 0:
        x = position[1]
        y = position[0]
        solv = [grid[x][y]]
        str_solv = str(solv[0])

        try:
            for i in range(0, max_len - 1):
                x = x + direction[1]
                y = y + direction[0]
                if y >= 0 and x >= 0:
                    solv.append(grid[x][y])
                    str_solv = str_solv + solv[i + 1]
        except:
            IndexError

        return str_solv
    else:
        return ""


def show_solution(grid, word, solution):
    """Checks if the user inputted a  false boolean and if so prints that the word couldn't be found. Creates
    a copy of the grid and separates the solution into four variables. creates an empty string for the solution
    variable. Uses a for loop between 0 and the length of the word that uses the starting point of the solution
    and continually adds the ending of the solution until the word should be completed. Capitalizes the location on the
    copied grid and adds the letter to a string. Uses an exception in case the word is out of bounds.
    Uses an if statement to check if the string is equal to the inputted word.
    If yes it outputs the word and the copied grid, if not it prints that the word could not be found."""

    if solution == False:
        print(word + " is not found in this word search")

    else:
        grid_copy = copy_word_grid(grid)
        start_x = solution[0][0]
        start_y = solution[0][1]
        end_x = solution[1][0]
        end_y = solution[1][1]
        str_solv = ""

        try:
            for i in range(0, len(word)):
                if start_y < 0:
                    start_y = start_y * -1
                str_solv = str_solv + str(grid_copy[start_y][start_x])
                grid_copy[start_y][start_x] = grid_copy[start_y][start_x].capitalize()
                start_x = start_x + end_x
                start_y = start_y + end_y
        except:
            IndexError
        if str_solv == word:
            print(str_solv.upper() + " can be found as below")
            print_word_grid(grid_copy)
        else:
            print(word + " is not found in this word search")
            return


def find(grid, word):
    """ Uses 3 nested for loops to check in each row, column, and for each direction in the specified height, width,
    and directions. For each letter location, checks if the solution is found by adding the specified direction to
    the location. Adds solution letters to a string and checks that string against sought after word, if equal
    returns the location and direction of the solution."""

    y = len(grid)
    x = len(grid[0])

    for row in range(0,y):
        for letter in range(0,x):
            for direction in DIRECTIONS:
                solution = ""
                r = row
                l = letter
                try:
                    for i in range(0, len(word)):
                        solution = solution + str(grid[r][l])
                        r = r + direction[1]
                        l = l + direction[0]
                        if solution == word:
                            return (letter,row), direction
                except:
                    IndexError
    else:
        return False


def find_all(grid,words):
    """ Uses find function to add the location and solution of each word to the index of the sought after word. Returns
    a dictionary of given words and their solution and location if found or else False if not. """

    answers = {}
    for i in range(0,len(words)):
        answers[words[i]] = find(grid,words[i])
    return answers


def generate(width,height,words):
    """ Creates a grid with the specified dimensions. Places random letters in each spot in the grid.
    Uses a for loop to to check each word. Checks words with while loop which creates random numbers for location
    and direction 100 times. Checks each of the potential solutions against previous solutions, if solution is identical
    sets a bool to false. Uses nested if statements to first check if prior solutions
    with different letters aren't used. Then checks if the word and direction goes out of bounds, then makes sure
    the height isn't negative (in case of up right). If all tests are passed, the random solution is stored and the loop
    is cancelled. Uses if statement to further test validity of words, if passed uses a for statement to place words
    in their locations in the grid."""

    grid = []
    solutions = []
    placed_words = []
    for row in range(height):
        grid.append([])
        for column in range(width):
            grid[row].append(column)

    for row in range(height):
        for column in range(width):
            grid[row][column] = chr(random.randint(ord('a'), ord('z')))

    for word in words:
        i = 0
        while i < 100:
            location = [random.randint(0, width), random.randint(0, height-1)]
            direction = DIRECTIONS[random.randint(0, 3)]
            no_repeat = True
            for n in range(0,len(word)):
                if [location[0] + (direction[0] * n), location[1] + (direction[1] * n)] in solutions:
                    no_repeat = False

            if no_repeat:
                if location[0]+(direction[0]*len(word)) <= width-1 and location[1]+(direction[1]*len(word)) <= height-1:
                    if location[1] + (direction[1] * len(word)) > 0:
                        l1 = location[1]
                        l0 = location[0]
                        d = direction
                        i = 100
                        placed_words.append(word)

            i = i + 1

        if word in placed_words:
            for j in range(0, len(word)):
                solutions.append([l0, l1])
                grid[l1][l0] = str(word[j])
                l1 = l1 + d[1]
                l0 = l0 + d[0]

    return grid, placed_words
