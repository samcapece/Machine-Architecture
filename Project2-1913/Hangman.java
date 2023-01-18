// Sam Capece
// Project 2


public class Hangman extends Game{

    private int minLength, maxLength, maxGuess, guessCount=0;
    private String guess, answer, hiddenAnswer = "";
    private WordsList words;

    /**
     * Constructor method sets the private variables that determine the wordlist, the length of the word, and the maximum guesses.
     * **/

    public Hangman(WordsList words, int minLength, int maxLength,
    int maxGuess){
        this.minLength = minLength;
        this.maxLength = maxLength;
        this.maxGuess = maxGuess;
        this.words = words;
    }

    /**
     * Resets all variables for a new game and returns
     * the welcome message using these variables.
     * Creates the hidden answer with a for loop using the answers length and underscores.
     * **/


    @Override
    protected String prepToPlay() {

        answer = words.getWord(minLength,maxLength);
        hiddenAnswer = "";
        guessCount = 0;
        for(int i=0; i<answer.length(); i++) {
            hiddenAnswer = hiddenAnswer + "_";
        }

        return "I've picked a " + answer.length() + " letter word." +
                " Guess letters you think are in the word. You get " +
                maxGuess + " guesses.";
    }

    /**
     * Checks if the game is over by checking if the answer is equal to the hidden answer or if the user
     * has used all of their guesses
     * **/

    @Override
    protected boolean isOver() {
        if(hiddenAnswer.equals(answer) || guessCount >= maxGuess){
            return true;
        }
        else{
            return false;
        }

    }

    /**
     * Checks if a move is valid by making sure the length is 1, ie: the user only inputted 1 character
     * **/

    @Override
    protected boolean isValid(String move) {
        if(move.length() == 1){
            return true;
        }
        else{
            return false;
        }
    }

    /**
     * Processes a move by adding to the guess count, and then changes the hidden answer
     * so that each index of _ where a letter would be gets changed to that letter if the move matches
     * accomplishes this using substrings. Returns the new answer.
     * **/

    @Override
    protected String processMove(String move) {
        char moveChar = move.charAt(0);
        char answerChar;
        guessCount = guessCount + 1;

        for(int i = 0 ; i<answer.length(); i++){
            answerChar = answer.charAt(i);
            if(moveChar == answerChar){
                hiddenAnswer = hiddenAnswer.substring(0,i) + move +
                        hiddenAnswer.substring(i +1);
            }
        }
        return hiddenAnswer;
    }

    /**
     * returns the answer at the end of the game
     * **/

    @Override
    protected String finalMessage() {
        return "The word was: " + answer;
    }

    /**
     * returns the name of the game
     * **/

    @Override
    public String getName() {
        String hangman = "Hangman";
        return hangman;
    }
}
