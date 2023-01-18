//Samuel Capece
//Project 2

import java.util.Random;

public class NumberGuesser extends Game{

    private int maxNumber, maxGuesses, guessCount=0, answer, guess, n;
    private Random rng;
    String strAnswer;

    /**
     * Constructor method sets private variables for the rng, the maximum number, and the maximum guesses.
     * **/
    public NumberGuesser(Random rng, int maxNumber, int maxGuesses){
        this.rng = rng;
        this.maxNumber = maxNumber;
        this.maxGuesses = maxGuesses;
    }

    /**
     * Resets all variables to prepare for a new game. Gets number of digits in answer. Returns welcome message
     * using private variables.
     * **/
    @Override
    protected String prepToPlay() {
        guess = -1;
        answer = rng.nextInt(maxNumber)+1;
        guessCount = 0;
        strAnswer = String.valueOf(answer);
        n = strAnswer.length();

        return "I've picked a number 1 to " + maxNumber + ". You get " + maxGuesses +
                " guesses to guess it";
    }

    /**
     * Returns true when the game is over.
     * This occurs if the guess is equal to the answer or if the maximum amount of guesses has been reached.
     * **/
    @Override
    protected boolean isOver() {
        if(guess == answer || maxGuesses <= guessCount){
            return true;
        }
        else{
            return false;
        }
    }

    /**
     * Checks if a move is valid using a for loop. Converts each number in the string to a character and makes sure the character
     * is a digit using the isDigit character method.
     * **/
    @Override
    protected boolean isValid(String move) {
        for(int i = 0; i<move.length(); ++i){
            char moveChar = move.charAt(i);
            if(!Character.isDigit(moveChar)){
                return false;
            }
        }
        return true;
    }


    /**
     * Converts the move string to an int and updates the guess count. Checks if the guess is greater than or less than the
     * answer, in each case the method gives the user a hint if they were too high or too low. Otherwise, if the numbers
     * are equal, the method tells the user they got it right.
     * **/
    @Override
    protected String processMove(String move) {
        guess = Integer.parseInt(move);
        guessCount = guessCount + 1;
        if(guess < answer){
            return "Too Low";
        } else if(guess > answer){
            return "Too High";
        } else {
            return "That's it!";
        }
    }

    /**
     * Prints the answer
     * **/
    @Override
    protected String finalMessage() {
        return "The number was: " + answer;
    }

    /**
     * Returns the name of the game
     * **/
    @Override
    public String getName() {
        String NumberGuesser = "NumberGuesser";
        return NumberGuesser;
    }
}
