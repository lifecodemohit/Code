import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import javax.script.ScriptEngine;


public class Calc extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	double ans, v1, v2;
	String input="";
	char operator;
	boolean dotFlag = false;
	
	JFrame calc;
	JPanel p1, p2, p3, p4, p5, p6;
	private JTextField tField;
	private JButton num0, num1, num2, num3, num4, num5, num6, num7, num8, num9;
	private JButton add, sub, mul, div, dot, equals, backspace, clear, sqrt, mod;
	ScriptEngineManager mgr = new ScriptEngineManager();
	ScriptEngine engine = mgr.getEngineByName("JavaScript");

	Calc(){
		calc = new JFrame("BODMAS");
		
		p1 = new JPanel();
		p2 = new JPanel();
		p3 = new JPanel();
		p4 = new JPanel();
		p5 = new JPanel();
		p6 = new JPanel();
		
		tField = new JTextField("0", 20);
		tField.setEditable(false);
		tField.setBackground(Color.white); 

		num0 = new JButton("0");
		num1 = new JButton("1");
		num2 = new JButton("2");
		num3 = new JButton("3");
		num4 = new JButton("4");
		num5 = new JButton("5");
		num6 = new JButton("6");
		num7 = new JButton("7");
		num8 = new JButton("8");
		num9 = new JButton("9");
		
		add = new JButton("+");
		sub = new JButton("-");
		mul = new JButton("*");
		div = new JButton("/");
		dot = new JButton(".");
		equals = new JButton("=");
		backspace = new JButton("<---");
		clear = new JButton("AC");
		sqrt = new JButton("sqrt");
		mod = new JButton("mod");
		
		p2.add(num7);
		p2.add(num8);
		p2.add(num9);
		p2.add(add);
		p2.add(clear);
		
		p3.add(num4);
		p3.add(num5);
		p3.add(num6);
		p3.add(sub);
		p3.add(sqrt);
		
		p4.add(num1);
		p4.add(num2);
		p4.add(num3);
		p4.add(mul);
		p4.add(backspace);
		
		p5.add(num0);
		p5.add(dot);
		p5.add(div);
		p5.add(equals);
		p5.add(mod);
		
//		p6.add(backspace);
//		p6.add(clear);
//		p6.add(sqrt);
//		p6.add(mod);
		
		
		FlowLayout f1 = new FlowLayout(FlowLayout.CENTER);
		FlowLayout f2 = new FlowLayout(FlowLayout.LEFT,2,1);
		
		p1.setLayout(f1);
		p2.setLayout(f2);
		p3.setLayout(f2);
		p4.setLayout(f2);
		p5.setLayout(f2);
		p6.setLayout(f2);
		
		calc.add(tField);
//		calc.add(p6);
		calc.add(p2);
		calc.add(p3);
		calc.add(p4);
		calc.add(p5);
		
		calc.setLayout(new GridLayout(5,5));
//		calc.setSize(250, 250);		
		calc.setVisible(true);
		calc.pack();
		
		num0.addActionListener(this);
		num1.addActionListener(this);
		num2.addActionListener(this);
		num3.addActionListener(this);
		num4.addActionListener(this);
		num5.addActionListener(this);
		num6.addActionListener(this);
		num7.addActionListener(this);
		num8.addActionListener(this);
		num9.addActionListener(this);
		
		add.addActionListener(this);
		sub.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		dot.addActionListener(this);
		equals.addActionListener(this);
		backspace.addActionListener(this);
		clear.addActionListener(this);
		sqrt.addActionListener(this);
		mod.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e){
		Object act = e.getSource();
		if(act==num0){
			input+=0;
			tField.setText(input);
		}
		else if(act==num1){
			input+=1;
			tField.setText(input);
		}
		else if(act==num2){
			input+=2;
			tField.setText(input);
		}
		else if(act==num3){
			input+=3;
			tField.setText(input);
		}
		else if(act==num4){
			input+=4;
			tField.setText(input);
		}
		else if(act==num4){
			input+=4;
			tField.setText(input);
		}
		else if(act==num5){
			input+=5;
			tField.setText(input);
		}
		else if(act==num6){
			input+=6;
			tField.setText(input);
		}
		else if(act==num7){
			input+=7;
			tField.setText(input);
		}
		else if(act==num8){
			input+=8;
			tField.setText(input);
		}
		else if(act==num9){
			input+=9;
			tField.setText(input);
		}
		
		
		
		else if(act==add){
			input+="+";
			tField.setText(input);
		}
		else if(act==sub){
			input+="-";
			tField.setText(input);
		}
		else if(act==mul){
			input+="*";
			tField.setText(input);

		}
		else if(act==div){
			input+="/";
			tField.setText(input);

		}
		else if(act==mod){
			input+="%";
			tField.setText(input);
		}
		
		else if(act==equals){
			try {
				ans = (double) engine.eval(input);
			} catch (ScriptException e1) {
				e1.printStackTrace();
			}
			input = "" + ans;
			tField.setText("" + ans);
		}
		else if(act==clear){
			input = "";
			ans = 0;
			tField.setText("");
			dotFlag = false;
		}
		else if(act==dot){
			input+=".";
			tField.setText(input);
		}
		else if(act==backspace){
			input = tField.getText();
			input = input.substring(0, input.length()-1);
			tField.setText(input);
		}
		else if(act==sqrt){
			try {
				ans = (double) engine.eval(input);
			} catch (ScriptException e1) {
				e1.printStackTrace();
			}

			ans = Math.sqrt(ans);
			input = ""+ans;
			tField.setText(input);
			
		}
		calc.getRootPane().setDefaultButton(equals);
	}
	
	public static void main(String args[]){
		System.out.println("This supports BODMAS"); 
		@SuppressWarnings("unused")
		Calc myCalc = new Calc();
	}
	
	
}
