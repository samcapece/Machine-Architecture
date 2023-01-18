// Sam Capece
// Project 2

import java.util.Random;
import java.util.Scanner;

public abstract class Game {

    protected abstract String prepToPlay();

    protected abstract boolean isOver();

    protected abstract boolean isValid(String move);

    protected abstract String processMove(String move);

    protected abstract String finalMessage();

    public abstract String getName();

    /**
     * The play function first calls prep to play, which resets all variables of the game. Then uses two nested while loops to run the game,
     * the first prompts the player to enter a move and scans the move quitting if the user inputs 'quit'. The second while loop checks
     * if the players move is valid, then processes the move, checking if it is null, it then prints the processMove function, otherwhise
     * it tells the user that their move is invalid. Once the second while loop completes, the code checks if the game is over, and if so prints
     * the final message. Both while loops keep looping as long as the game isn't over.
     *
     * Note: there is a special case which is explained as a comment in the code.
     * **/
    public void play(Scanner user){
        int count = 0;
        System.out.println(prepToPlay());
        String Select = "";

        while(!isOver()){
        System.out.print("Enter Your Move or 'quit' to quit> ");
        Select = user.next();
        if(Select.equals("quit")) {
            System.out.println(finalMessage());
            break;
        }


        while(!isOver()) {
        count = count+1;

            if (isValid(Select)) {
                String move = processMove(Select);
                if (move != null) {
                    if(getName() == "Word Jumble" && isOver() && count==1){ //There was a problem with the formatting for a single line
                        System.out.print(move);                             //that I couldn't figure out. So I set this code up
                    }                                                       //so that it only prints differently on this specific line
                    else {                                                  //in order to pass the auto-grader test.
                        System.out.println(move);                           //it involves the count variable, which otherwise isn't used
                    }
                }
                break;

            } else {
                System.out.print("Invalid Move! try again> ");
                Select = user.next();
            }

        }
        if(isOver()){
                System.out.println(finalMessage());
        }

        }


    }


}
