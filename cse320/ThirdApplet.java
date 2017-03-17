// You may study, use, modify, and distribute this example for any purpose.
// This example is provided WITHOUT WARRANTY either expressed or implied.

import java.awt.*;
import java.applet.Applet;
/** This simulates a simple interaction with
	feedback in the center and some stimuli(buttons) underneath.
*/
public class ThirdApplet extends Applet {
/** A piece of text identifying the last click*/
	protected Label response;
/** An array of buttons */
	protected Button stimuli[];
/** The place in the Applet where the Buttons are put. */
	protected Panel  buttons;

/** Layout and display text and buttons.

    Set the background to white and put the label in the center,
	create a grey panel. Create and add buttons to this
	panel
*/
    public ThirdApplet() {
	this.setBackground(Color.white);
	this.setLayout(new BorderLayout(10,10));

	response=new Label("Hi there! Are you in a good mood?");
	add("Center", response);

	buttons=new Panel();
	buttons.setBackground(Color.lightGray);
	buttons.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));

	  stimuli=new Button[3];//until now the individual buttons
				//did not exist

	  stimuli[0]=new Button("Yes");
	  buttons.add("Yes", stimuli[0]);

	  stimuli[1]=new Button("No");
	  buttons.add("No", stimuli[1]);

	  stimuli[2]=new Button("IDK");
	  buttons.add("IDK", stimuli[2]);

	this.add("South", buttons);

    }//constructor
/** Reports all events by changing the Label.

	Indicates which button is clicked (if any)
	else changes response to "Clunk!"
	After changing response it redisplays it.
*/
    public boolean action(Event event, Object arg) {
	if (event.target instanceof Button) {
		response.setText(arg.toString()+"!?!?!?!?!");
		if(event.target == stimuli[0])
			response.setBackground(Color.green);

		else if(event.target == stimuli[1])
			response.setBackground(Color.red);

		else
			response.setBackground(Color.yellow);
		response.setVisible( true);
		return true;
	} else { 
		response.setText("Clunk!");//This doesn't happen.....why?
		response.setBackground(Color.blue);
		response.setVisible( true);
		return false;
	}
    }//action

/**Creates a frame in which the Applet can run, for debugging
	purposes.
*/
    public static void main(String args[]) {
	ThirdApplet dialogTest = new ThirdApplet();
		dialogTest.init();
		dialogTest.start();
	Frame f = new Frame("DialogTest");
		f.setBackground(Color.white);
		f.add("Center", dialogTest);
		f.setSize(300, 100);
		f.setVisible( true);
    }//main
}//ThirdApplet

