import java.util.Random;

public class RPS extends Game{
    private Random rng;
    private int requiredWins, maxLosses, wins=0, losses=0;

    /**
     * Constructor sets private variables for the rng, the required wins, and the maximum losses.
     * **/
    public RPS(Random rng, int requiredWins, int maxLosses){
        this.rng = rng;
        this.requiredWins = requiredWins;
        this.maxLosses = maxLosses;
    }

    /**
     * Resets variables for a new game. Returns new game message using private variables.
     * **/
    @Override
    protected String prepToPlay() {
        wins = 0;
        losses = 0;

        return "Enter rock, paper, or scissors. " +
                "Beat me " + requiredWins + " times before I win " + maxLosses + "times!";
    }

    /**
     * The game is over is the losses or wins exceed the required amount.
     * **/
    @Override
    protected boolean isOver() {
        if(maxLosses <= losses || requiredWins <= wins){
            return true;
        } else {
            return false;
        }
    }

    /**
     * A move is valid if it is either rock paper or scissors.
     * **/
    @Override
    protected boolean isValid(String move) {
        if(move.equals("rock") || move.equals("paper") || move.equals("scissors")){
            return true;
        } else {
            return false;
        }

    }

    /**
     * Sets the AI move to an int between 0 and 2. Sets win and loss messages. Sets the number value of AI's move to its
     * rock paper scissors equivalent (commented below). Sets user input to its numerical equivalent. Uses if else statements
     * to compare all possible moves and sets the outcome string to either win or lose. Checks if outcome is win or lose and
     * updates the appropriate variable. Returns the AI's move and the user's move as well as the outcome.
     * **/
    @Override
    protected String processMove(String move) {
        // /0: rock /1: paper /2: scissors
        int AImove = rng.nextInt(3);
        int moveNum = -1;
        String outcome = "";
        String AIstring = "";
        String lose = "you lose";
        String win = "you Win";

        if(AImove == 0){
            AIstring = "rock";
        } else if(AImove == 1){
            AIstring = "paper";
        } else {
            AIstring = "scissors";
        }

        if(move.equals("rock")){
            moveNum = 0;
        } else if(move.equals("paper")){
            moveNum = 1;
        } else {
            moveNum = 2;
        }


        if(AImove == moveNum){
            outcome =  "We Tie";
        } else if(AImove == 0 && moveNum ==  1) {
            outcome = win;
        } else if(AImove == 0 && moveNum == 2) {
            outcome = lose;
        } else if(AImove == 1 && moveNum == 0) {
            outcome = lose;
        } else if(AImove == 1 && moveNum == 2) {
            outcome = win;
        } else if(AImove == 2 && moveNum == 0) {
            outcome = win;
        } else if(AImove == 2 && moveNum == 1) {
            outcome = lose;
        }

        if(outcome == win){
            wins = wins + 1;
        } else if(outcome == lose){
            losses = losses + 1;
        }


        return AIstring + " vs. " + move + " " + outcome;
    }

    /**
     * Returns a losing message if the losses exceed the maximum. Otherwise, returns the winning message.
     * **/
    @Override
    protected String finalMessage() {
        if(maxLosses <= losses){
            return "You lose the set";
        } else {
            return "You win the set";
        }
    }

    /**
     * Returns the name of the game.
     * **/
    @Override
    public String getName() {
        String RPS = "Rock Paper Scissors";
        return RPS;
    }
}
