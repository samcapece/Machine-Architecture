// Samuel Capece
// Project 3

public class HuffmanCodeBook {

    private BinarySequence[] seq = new BinarySequence[10];
    private char[] charArr = new char[10];
    private int count = 0;
    private int length = 10;

    /**
     * Default Constructor
     * **/
    public HuffmanCodeBook(){

    }


    /**
    * This method first checks the if the amount of items in the array of
    * Binary Sequences has reached capacity, if so it creates a new array
    * of double the size of the original(which starts at 10) and copies
    * the items of the old array into the new one, does this for the char array
     * as well. Finally, sets the new arrays to the private variable where the
     * old arrays was contained.
     *
    * Sets the given binary sequence to the next open spot in the sequence array
    * adds the character of the binary sequence to the character array.
     * Both arrays are then sorted by character using selection sort.
    * **/
    public void addSequence(char c, BinarySequence seq){
        if(count == length){
            BinarySequence[] seq2 = new BinarySequence[count*2];
            char[] charArr2 = new char[count*2];
            for(int i =0; i<count; i++){
                seq2[i] = this.seq[i];
                charArr2[i] = charArr[i];
            }
            charArr = charArr2;
            this.seq = seq2;
            length = count*2;
        }

        this.seq[count] = seq;
        charArr[count] = c;
        count++;

        for(int i = 0; i < count; i++){
            for(int j = i+1; j<count; j++){
                if(charArr[j] < charArr[i]){
                    char temp = charArr[i];
                    charArr[i] = charArr[j];
                    charArr[j] = temp;

                    BinarySequence temp2 = this.seq[i];
                    this.seq[i] = this.seq[j];
                    this.seq[j] = temp2;
                }
            }
        }

    }

    /**
     * Checks the character array to see if the letter in question is contained
     * within it using Binary Search.
     * **/
    public boolean contains(char letter){
        int l = 0, h = count-1;

        while(l <= h){
            int m = l + (h - l) /2;

            if(charArr[m] < letter){
                l = m + 1;
            } else if(charArr[m] > letter){
                h = m - 1;
            } else {
                return true;
            }

        }

        return false;
    }

    /**
     * Uses the contains method to check if the char array contains each
     * of the letters in the given string.
     * **/
    public boolean containsAll(String letters){
        for(int i=0; i<letters.length(); i++){
            if(!contains(letters.charAt(i))){
                return false;
            }
        }
        return true;
    }

    /**
     * Checks if the char string contains the given char using Binary Search,
     * if so gets the index of the character and returns the corresponding sequence.
     * Otherwise, returns null
     * **/
    public BinarySequence getSequence(char c) {
        int l = 0, h = count-1;

        while(l <= h){

            int mid = l + (h - l) / 2;

            if(charArr[mid] == c){
                return seq[mid];
            }

            if(charArr[mid] < c){
                l = mid + 1;
            } else {
                h = mid - 1;
            }

        }

        return null;
    }

    /**
     * Checks if the given string's characters are all contained in the array of
     * binary sequences, if so the method uses a for loop to add the sequence for
     * each of the characters to a string. Then a new binary sequence is created
     * with the string and returned. If not all the letters are contained, null is
     * returned.
     * **/
    public BinarySequence encode(String s){
        if (containsAll(s)){
            BinarySequence bs = new BinarySequence();
            for(int i = 0; i<s.length(); i++){
                char c = s.charAt(i);
                BinarySequence charBS = getSequence(c);
                bs.append(charBS);
            }

            return bs;
        }
        else {
            return null;
        }
    }

    /**
     * Method for getting the count of the codebook, used for looping
     * **/
    public int getCount(){
        return count;
    }

    /**
     * Method for other functions to loop through characters in codebook,
     * returns null if the user tries to iterate to an index that exceeds
     * the count (ie: indexes containing characters).
     * **/
    public Character loop(int i){
        if(i<count){
            return charArr[i];
        } else {
            return null;
        }
    }

}
