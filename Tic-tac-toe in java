//Tic-tac-toe for 2 players in java 

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

public class TicTacToe implements ActionListener {

	JFrame window = new JFrame("Tic-tac-toe for 2 players");
	JMenuBar mainM = new JMenuBar();
	
	JMenuItem NewGame = new JMenuItem("New Game"),
	instruction = new JMenuItem("Instruction"),
	exit = new JMenuItem("Exit"),
	info = new JMenuItem("Information");

	JButton btn[][] = new JButton[3][3];
	JButton back = new JButton("◀back");
	JButton start = new JButton("start");
	
	JPanel mainGame = new JPanel();
	JPanel PlayingField = new JPanel();
	JPanel North = new JPanel();
	JPanel South = new JPanel();
	JPanel Top = new JPanel();
	JPanel Bottom = new JPanel();
	JLabel title = new JLabel("Tic-tac-toe game by Demian");
	
	int wonNumber1 = 1, wonNumber2 = 1, wonNumber3 = 1;
	int turn; 
	boolean clicked = false;
	boolean inGame = false;
	boolean win = false;
	String message = "";
	JTextArea txtMessage = new JTextArea();
	int wonNum1,wonNum2,wonNum3 = 1;
	
	public TicTacToe(){
		window.setSize(412,268);
		window.setLocation(450, 260);
		window.setResizable(false);
		window.setLayout(new BorderLayout());
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		//패널 위치
		
		North.setLayout(new FlowLayout(FlowLayout.CENTER));
		South.setLayout(new FlowLayout(FlowLayout.CENTER));
		Top.setLayout(new FlowLayout(FlowLayout.CENTER));
		Bottom.setLayout(new FlowLayout(FlowLayout.CENTER));
		
		txtMessage.setBackground(new Color(238, 238, 238));
		
		//메뉴 추가 
		mainM.add(NewGame);
		mainM.add(instruction);
		mainM.add(info);
		mainM.add(exit);
		mainGame.add(start);
		
		//각각에 액션 리스너 추가 
		NewGame.addActionListener(this);
		instruction.addActionListener(this);
		info.addActionListener(this);
		exit.addActionListener(this);
		start.addActionListener(this);
		back.addActionListener(this);
		//게임판 레이아웃 (3x3)
		PlayingField.setLayout(new GridLayout(3,3,2,2));
		
		//게임 판에 9개의 버튼 추가
		for(int i = 0; i < 3; i++)
			for(int j =0; j < 3; j++)
		{
			btn[i][j] = new JButton();
			btn[i][j].setBackground(new Color(220, 220, 220));
			btn[i][j].addActionListener(this);
			PlayingField.add(btn[i][j]);
		}

		//초기 화면: 메인, 타이틀 
		North.add(mainM);
		South.add(title);
		
		//윈도우에 노스패널은 노스에, 사우스 패널은 센터에 배치 
		window.add(North,BorderLayout.NORTH);
		window.add(South,BorderLayout.CENTER);
		window.setVisible(true);
	}
	
	//액션 추가 
	public void actionPerformed(ActionEvent click){
		Object source = click.getSource();
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				if(source == btn[i][j] && turn < 10)
				{
					clicked = true;
					if(!(turn % 2 == 0))
						btn[i][j].setText("X");
					else
						btn[i][j].setText("O");
						btn[i][j].setEnabled(false);
						PlayingField.requestFocus();
						turn++;
				}
			}
		
		if(clicked)
		{
			winCheck2(btn);
			clicked = false;
		}
		
		if(source == NewGame) 
		{
			clearPanel();
			South.setLayout(new GridLayout(2, 1, 2, 5));
			Top.add(mainGame); 
			Bottom.add(back);
			South.add(Top);
			South.add(Bottom);
		}
			
		else if(source == start)
		{
			if(inGame)
			{
				int option = JOptionPane.showConfirmDialog(null, "Your current game will be lost." + "\n" + 
					"Are you sure you want to continue?", "Quit Game?", JOptionPane.YES_NO_OPTION);
				if(option == JOptionPane.YES_OPTION) 
					inGame = false;
			}
			
			if(!inGame)
			{
				turn = 1;
				for(int i=0; i<3; i++)
					for(int j = 0; j < 3; j++)
					{
						btn[i][j].setText("");
						btn[i][j].setBackground(new Color(220, 220, 220));
						btn[i][j].setEnabled(true);
					}
				showGame(); //판 새로 다시 만들고... 
			}
		}
					
		else if(source == exit)
		{
			int ask = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit?", 
			"Exit Game", JOptionPane.YES_NO_OPTION);
			
			if(ask == JOptionPane.YES_OPTION)
				System.exit(0);
		}
		
		else if(source == instruction || source == info)
		{
			clearPanel();
			String message = "";
			if(source == info) 
			{
				message = "Tic-tac-toe is a game for two players,\n"
				+ " X and O, who take turns marking the spaces in a 3×3 grid.\n"
				+ "The player who succeeds in placing three of their marks in a horizontal, \n"
				+ "vertical, or diagonal row wins the game.";
			}
			else 
			{
				message = "Info:\n\n" +
				"Title: Tic-Tac-Toe\n" +
				"Author: Demian\n" +
				"Version: 1.0";
			}
			txtMessage.setEditable(false);
			txtMessage.setText(message);
			South.setLayout(new GridLayout(2, 1, 2, 5));
			Top.add(txtMessage);
			Bottom.add(back);
			South.add(Top);
			South.add(Bottom);
		}
		
		else if(source == back)
		{
			if(inGame)
				showGame();
			else
			{
				clearPanel();
				South.setLayout(new FlowLayout(FlowLayout.CENTER));
				North.setVisible(true);
				South.add(title);
			}
		}
		South.setVisible(false);
		South.setVisible(true);
	}
	
	public void showGame()
	{
		clearPanel();
		inGame = true;
		South.setLayout(new BorderLayout());
		South.add(PlayingField, BorderLayout.CENTER);
		PlayingField.requestFocus();
	}
	
	public void winCheck2(JButton b[][])
	{
		if(winCheck1(b) == 1 || (winCheck1(b)!= 1 && turn>9)) {
			if(winCheck1(b) == 1)
			{
				if(turn % 2 == 0)
				{
					message = "X has won!";
				}
				else
				{
					message = "O has won!";
				}
			} else if(winCheck1(b) != 1 && turn>9) {
			message = "Both players have tied!";
			}
			JOptionPane.showMessageDialog(null, message);
		
		}
	}
	public int winCheck1(JButton b[][])
	{
		int i;
		
		for (i = 0; i < 3; i++)
			if (b[i][0].getText().equals( b[i][1].getText()) && b[i][0].getText().equals(b[i][2].getText()))
			{
				if (b[i][0].getText().equals("X") || b[i][0].getText().equals("O"))
				{
					b[i][0].setBackground(Color.white);
					b[i][1].setBackground(Color.white);
					b[i][2].setBackground(Color.white);
					return 1;
				}
			}
			else if (b[0][i].getText().equals( b[1][i].getText()) && b[0][i].getText().equals(b[2][i].getText()))
			{
				if (b[0][i].getText().equals("X") || b[0][i].getText().equals("O"))
				{
					b[0][i].setBackground(Color.white);
					b[1][i].setBackground(Color.white);
					b[2][i].setBackground(Color.white);
					return 1;
				}
			}
			else if (b[0][0].getText().equals(b[1][1].getText()) && b[0][0].getText().equals(b[2][2].getText()))
			{
				if (b[0][0].getText().equals("X") || b[0][0].getText().equals("O"))
				{
					b[0][0].setBackground(Color.white);
					b[1][1].setBackground(Color.white);
					b[2][2].setBackground(Color.white);
					return 1;
				}
			}
		
			else if (b[0][2].getText().equals(b[1][1].getText()) && b[0][2].getText().equals(b[2][0].getText()))
			{
				if (b[0][2].getText().equals("X") || b[0][2].getText().equals("O"))
				{
					b[0][2].setBackground(Color.white);
					b[1][1].setBackground(Color.white);
					b[2][0].setBackground(Color.white);
					return 1;
				}
				
			}
		return 0;
	}

	public void clearPanel()
	{
		South.remove(title);
		South.remove(Top);
		South.remove(Bottom);
		South.remove(PlayingField);
		Top.remove(mainGame);
		Top.remove(txtMessage);
		Bottom.remove(back);
	}
		
	public static void main(String[] args)
	{
		new TicTacToe();
	}
		
}
