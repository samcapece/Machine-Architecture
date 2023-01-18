// Samuel Capece
// Project 3

public class HuffmanNode {

    private HuffmanNode zero;
    private HuffmanNode one;
    private Character data;

    /**
     * Constructor for non-leaf nodes, sets the zero and one to inputted nodes,
     * sets data to null.
     * **/
    public HuffmanNode(HuffmanNode zero, HuffmanNode one){
        this.zero = zero;
        this.one = one;
        data = null;
    }

    /**
     * Constructor for leaf nodes, sets zero and one to null,
     * and data to the inputted character.
     * **/
    public HuffmanNode(char data){
        zero = null;
        one = null;
        this.data = data;
    }

    /**
     * Returns the zero of the node.
     * **/
    public HuffmanNode getZero() {
        return zero;
    }

    /**
     * Sets the zero of the node.
     * **/
    public void setZero(HuffmanNode zero){
        this.zero = zero;
    }

    /**
     * Returns the one of the node.
     * **/
    public HuffmanNode getOne(){
        return one;
    }

    /**
     * Sets the one of the node.
     * **/
    public void setOne(HuffmanNode one){
        this.one = one;
    }

    /**
     * Returns the data(character) within a node.
     * **/
    public Character getData(){
        return data;
    }

    /**
     * Sets the data within a node.
     * **/
    public void setData(char data){
        this.data = data;
    }

    /**
     * Checks if the node is a leaf by confirming that the data is not null.
     * **/
    public boolean isLeaf(){
        return data != null;
    }

    /**
     * Checks if each node is valid recursively. If the node
     * is a leaf and one and zero are null, true is returned.
     * Otherwise, if the node isn't a leaf and one and zero are not null,
     * the method is called again for the one and zero of the node.
     * Otherwise, the node is not valid and false is returned.
     * **/
    public boolean isValid(){

        if(isLeaf() && one == null && zero == null){
            return true;
        } else if(!isLeaf() && one != null && zero != null){
            return zero.isValid() && one.isValid();
        } else {
            return false;
        }

    }



}
