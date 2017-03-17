 	import java.applet.*;

 	import java.awt.*;

	public class HelloWorld extends Applet {

	      public void init() {

	          setSize(150,25);

	      }//init

	      public void paint(Graphics g) {
		
		  g.setColor(Color.blue);
		  g.setFont(new Font("Helvetica", Font.BOLD, 24));

	          g.drawString("Hello world!", 50, 25);

		  

	      }//paint

	  }//HelloWorld
