import java.util.Random;
import java.util.Scanner;

public class GameGrabber{

    private int n;
    private Game games[];
    private Scanner user;

    /**
     * Constructor, sets private variables of the class.
     * **/
    public GameGrabber(Game[] games, Scanner user){
        n = games.length;
        this.games = games;
        this.user = user;

    }

    /**
     * Uses a while loop checking if the number inputted by the user does not equal the length of the games array (which would be the quit option)
     * then uses a for loop to print the games menu and prompts the user to input a number. Uses a nested while loop with the same condition
     * to check if the input is valid and if so calls the play method in the game function, otherwise prompting the user to input a different number.
     * Once the user selects the quit number, the menu exits.
     * **/
    public void doMenu(){

        int userInt = -1;
        while(userInt != n) {
            for (int i = 0; i < n; i++) {
                System.out.println(i + ") " + games[i].getName());
            }
            System.out.println(n + ") Quit");
            System.out.print("Pick a game (0-" + n + ") ");
            userInt = user.nextInt();
            while (userInt != n) {
                if (userInt <= n  && userInt >= 0) {
                    games[userInt].play(user);
                    break;
                } else {
                    System.out.print("Pick a game (0-" + n + ") ");
                    userInt = user.nextInt();
                }
            }
        }
        System.out.println("goodbye");


    }

    /**
     * The main method sets up all the games in order to play them. It starts by creating variables from the rng,
     * the wordlist, and each of the four games (with numbers used in the tests). The method then creates an array
     * of the four games as well as a scanner. Then it creates a GameGrabber using the variables and calls doMenu.
     * **/
    public static void main(String[] args){
        Random rng = new Random();
        WordsList words = new WordsList(rng);
        Hangman hm = new Hangman(words, 4, 9, 10);
        NumberGuesser ng = new NumberGuesser(rng, 72, 5);
        RPS rps = new RPS(new Random(0), 10, 10);
        WordJumble wj = new WordJumble(words, rng, 2, 10, 3);
        Game[] games = new Game[]{hm,ng,rps,wj};
        Scanner scan = new Scanner(System.in);
        GameGrabber game = new GameGrabber(games, scan);
        game.doMenu();
    }

}
