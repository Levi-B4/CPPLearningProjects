#include "./Card.h"

//constructor - parameters: int value, int suit
Card::Card(int value, int suit){
    this->value = value;
    this->suit = suit;
}

//Getter - returns value as string
const char* Card::GetValueString(){
    switch(value){
        case ACE:
            return "ace";
        case TWO:
            return "two";
        case THREE:
            return "three";
        case FOUR:
			return "four";
		case FIVE:
			return "five";
		case SIX:
			return "six";
		case SEVEN:
			return "seven";
		case EIGHT:
			return "eight";
		case NINE:
			return "nine";
		case TEN:
			return "ten";
		case JACK:
			return "jack";
		case QUEEN:
			return "queen";
		case KING:
			return "king";

        default:
            return "ERROR";
    }
}

//Getter - get value
int Card::GetValue(){
    return value;
}

//Getter - returns value as string
const char* Card::GetSuitString(){
    switch(suit){
        case CLUB:
            return "club";
        case DIAMOND:
            return "diamond";
        case HEART:
            return "heart";
        case SPADE:
            return "spade";

        default:
            return "ERROR";
    }
}




//default destructor
Card::~Card(){}
