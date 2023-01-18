// Samuel Capece
// Project 3

public class HuffmanCodeTree {

    private HuffmanNode root;

    /**
     * Constructor when using a Huffman Node.
     * Sets the given root to the private root variable.
     * **/
    public HuffmanCodeTree(HuffmanNode root){
        this.root = root;
    }

    /**
     * Constructor when using a Huffman codebook.
     * Sets the root as an empty node. Then gets the size of the codebook.
     * Uses a for loop and the loop method in the codebook class to get each
     * character and sequence. Then the put method is used to put the
     * character in the tree based on the sequence.
     * **/
    public HuffmanCodeTree(HuffmanCodeBook codebook){
        root = new HuffmanNode(null,null);
        int count = codebook.getCount();
        for(int i = 0; i < count; i++){
            char c = codebook.loop(i);
            BinarySequence seq = codebook.getSequence(c);
            put(seq, c);
        }
    }

    /**
     * Uses the isValid method from the HuffmanNode class
     * to check if the tree is valid.
     * **/
    public boolean isValid(){
        return root.isValid();
    }

    /**
     * Sets the current Huffman Node to the root.
     * Sets the length to the size of the given Binary Sequence.
     *
     * For every bit in the given binary sequence, the bit is checked, if true the status of
     * the current node's 'One' node is checked, if null it is set as an empty node.
     * Then the current node is set to its 'One'. If the bit is false the same is done
     * but for the current node's 'Zero'.
     *
     * Once the loop is over, the method has arrived at the correct node and
     * sets its data as the given letter.
     * **/
    public void put(BinarySequence seq, char letter){
        HuffmanNode current = root;
        HuffmanNode previous;
        int length = seq.size();

        for(int i = 0; i < length; i++){
            if(seq.get(i)){
                if(current.getOne() == null){
                    current.setOne(new HuffmanNode(null, null));
                }
                current = current.getOne();
            } else {
                if(current.getZero() == null){
                    current.setZero(new HuffmanNode(null,null));
                }
                current = current.getZero();
            }

        }
        current.setData(letter);
    }

    /**
     * Sets the root of the tree to the 'current' node. Creates a StringBuilder in order
     * to efficiently create a string. Sets the size variable to the size of the binary
     * sequence.
     *
     * For every bit in the given binary sequence, the bit is checked, setting
     * the 'current' node to either its 'One' or 'Zero', then the current node is checked
     * to see if it's a leaf (or has data and null pointers). If the current node is a leaf
     * the StringBuilder is appended with the nodes data and the current node is reset
     * as the root.
     *
     * The StringBuilder is returned after being converted to a string.
     * **/
    public String decode(BinarySequence s){
        HuffmanNode current = root;
        StringBuilder sb = new StringBuilder();
        int size = s.size();
        for(int i = 0; i<size; i++){
            if(s.get(i)){
                current = current.getOne();
            } else {
                current = current.getZero();
            }
            if(current.isLeaf()){
                sb.append(current.getData());
                current = root;
            }
        }
        return sb.toString();
    }

}
