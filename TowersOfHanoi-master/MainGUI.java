
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.*;
import java.awt.event.*;

import javax.swing.*;

public class MainGUI extends JFrame {
	
	private TowersModel hanoi;
	private JMenuBar bar;
	private JMenu fileMenu;
	private JMenuItem exitItem;

	private int x;
	private int intTime;
	private int from;
	private int to;
	private int aux;
	public MainGUI() {
		//
		bar = new JMenuBar();
		fileMenu = new JMenu("file");
		exitItem = new JMenuItem("exit");
		exitItem.addActionListener(new ExitItemListener());
		fileMenu.add(exitItem);

		
		bar.add(fileMenu);

		setJMenuBar(bar);
		//
		//for frame
		setSize(900, 600);
		setTitle("Towers Of Hanoi");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//
	
		String in = JOptionPane.showInputDialog("How many rings: ");
		if(in == null)
			System.exit(1);
		this.x = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("seconds between moves:(hint .5 for half sec)");
		double time = Double.parseDouble(in);
		if(in == null)
			System.exit(1);
		in = JOptionPane.showInputDialog("\"From\" Peg:(1-3)");
		if(in == null)
			System.exit(1);
		from = Integer.parseInt(in);
		if(from > 3 || from < 1)
			System.exit(1);
		in = JOptionPane.showInputDialog("\"to\" Peg:(1-3)");
		if(in == null)
			System.exit(1);
		to = Integer.parseInt(in);
		if(to > 3 || to < 1)
			System.exit(1);
		in = JOptionPane.showInputDialog("\"Aux\" Peg:(1-3)");
		if(in == null)
			System.exit(1);
		aux = Integer.parseInt(in);
		if(aux > 3 || aux < 1)
			System.exit(1);
		
		this.intTime = (int) (time * 1000);
		if(x > 14)
			x = 14;
		if(x <= 0)
			x = 1;
		hanoi = new TowersModel(this, x, intTime,calcPeg(from));
		setLocationRelativeTo(null);
		//setResizable(false);	
		setVisible(true);
	}
	public void startAnimation(){
		hanoi.towers(x,calcPeg(from),calcPeg(to),calcPeg(aux));
	}
	public void reverseAnimation(){
		hanoi.towers(x,calcPeg(to),calcPeg(from),calcPeg(aux));
	}
	

	public static void main(String[] args) {
		boolean done = false;
		while(!done){
			MainGUI m = new MainGUI();
			try {
				Thread.sleep(m.getIntTime());
			} catch (InterruptedException e) {
				System.err.println(e);
				System.exit(1);
			}
			m.startAnimation();
			try {
				Thread.sleep(m.getIntTime());
			} catch (InterruptedException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
	}
	//
	private class ExitItemListener implements ActionListener{
		public void actionPerformed(ActionEvent evt){
			exitItemActionPerformed(evt);
		}
	}
	
	private void exitItemActionPerformed(ActionEvent evet){
		System.exit(0);
	}
	//
	public int getIntTime() {
		return intTime;
	}
	
	public int calcPeg(int peg){
		if(peg == 1){
			return TowersComponent.P_ONE_BASE;
		}
		if(peg == 2){
			return TowersComponent.P_TWO_BASE;
		}
		if(peg == 3)
				return TowersComponent.P_THREE_BASE;
		
		return TowersComponent.P_ONE_BASE;
	}
}
