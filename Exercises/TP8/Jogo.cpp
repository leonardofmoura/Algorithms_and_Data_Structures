#include "Jogo.h"

BinaryTree<Circulo> & Jogo::getJogo() {
	return jogo;
}


ostream &operator << (ostream &os, Circulo &c1)
{
	string estadoStr;
	if (c1.estado) estadoStr="true"; else estadoStr="false";
	os << c1.pontuacao << "-" << estadoStr  << "-" << c1.nVisitas << endl;
	return os;
}

BinaryTree<Circulo> Jogo::generate_game(int i, int niv, vector<int> &pontos, vector<bool> &estados) {
	Circulo current_node(pontos[i],estados[i]);

	if (niv == 0) {
		return BinaryTree<Circulo>(current_node);
	}
	else {
		BinaryTree<Circulo> left_node = generate_game(2*i+1,niv-1,pontos,estados);
		BinaryTree<Circulo> right_node = generate_game(2*i+2,niv-1,pontos,estados);
		return BinaryTree<Circulo>(current_node,left_node,right_node);
	}


}

BinaryTree<Circulo> Jogo::iniciaJogo(int pos,int niv, vector<int> &pontos, vector<bool> &estados)
{
	Circulo c1(pontos[pos],estados[pos]);
	if (niv==0) return BinaryTree<Circulo>(c1);
	BinaryTree<Circulo> filhoEsq=iniciaJogo(2*pos+1,niv-1,pontos, estados);
	BinaryTree<Circulo> filhoDir=iniciaJogo(2*pos+2,niv-1,pontos, estados);
	return BinaryTree<Circulo>(c1, filhoEsq, filhoDir);
}

Jogo::Jogo(int niv, vector<int> &pontos, vector<bool> &estados)
{
	iniciaJogo(0,niv,pontos,estados);
}


string Jogo::escreveJogo()
{
	// a alterar
	return "";
}


int Jogo::jogada()
{
	// a alterar
	return 0;
}



int Jogo::maisVisitado()
{
	// a alterar
	return 0;
}




