import java.util.Random;

public class WordJumble extends Game{

    private int minWordLen, maxWordLen, maxGuesses, guessCount=0;
    private Random rng;
    private WordsList w1;
    private String answer, guess;

    /**
     * Constructor method sets private variables for the wordlist, the rng, the word length, and the maximum guesses.
     * **/
    public WordJumble(WordsList w1, Random rng, int minWordLen, int maxWordLen, int maxGuesses){
        this.w1 = w1;
        this.rng = rng;
        this.minWordLen = minWordLen;
        this.maxWordLen = maxWordLen;
        this.maxGuesses = maxGuesses;
    }

    /**
     * Resets variables for new game. Creates a character array and converts the answer string to the array. Uses a for
     * loop to create random numbers with a max of the answer's length, then swaps the array values of the answer array
     * using the random integer. This for loop has the length of the answer iterations in order to ensure every possible
     * swap is accounted for. Then uses another for loop to convert the swapped array back to a string. Returns the jumbled
     * string and the amount of guesses the user has to guess it.
     * **/
    @Override
    protected String prepToPlay() {
        answer = w1.getWord(minWordLen,maxWordLen);
        guessCount = 0;
        guess = "";
        String jumble = "";
        char[] answerArr = answer.toCharArray();

        for(int i=0; i<answerArr.length; i++){
            int rand = rng.nextInt(answer.length());
            char temp;
            temp = answerArr[i];
            answerArr[i] = answerArr[rand];
            answerArr[rand] = temp;
        }

        for(int i=0; i<answerArr.length; i++){
            jumble = jumble + answerArr[i];
        }

        return "The following is a jumbled up word: " + jumble + " " +
                "You get " + maxGuesses + " guesses to guess it";
    }

    /**
     * The game is over if the answer equals the user's guess or if the guess count reaches the maximum guesses.
     * **/
    @Override
    protected boolean isOver() {
        if(answer.equals(guess) || guessCount >= maxGuesses){
            return true;
        }
        else {
            return false;
        }
    }

    /**
     * All entries are valid.
     * **/
    @Override
    protected boolean isValid(String move) {
        return true;
    }

    /**
     * Sets the guess variable to the move, updates the guess count. Uses an if statement to check if the answer equals
     * the guess. If not the method returns a 'wrong' string, otherwise it returns nothing.
     * **/
    @Override
    protected String processMove(String move) {
        guess = move;
        guessCount = guessCount + 1;
        if(!answer.equals(guess)){
            return "That's not it";
        }
        else{
            return "";
        }
    }

    /**
     * The final message gives the user the answer.
     * **/
    @Override
    protected String finalMessage() {
        return "The word was " + answer;
    }

    /**
     * Returns the name of the game.
     * **/
    @Override
    public String getName() {
        String WordJumble = "Word Jumble";
        return WordJumble;
    }
}
