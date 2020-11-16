
#ifndef SRC_VETERINARIO_H_
#define SRC_VETERINARIO_H_

#include <string>
using namespace std;

class Veterinario {
	string nome;
	long codOrdem;
public:
	Veterinario(string nome, int cod);
	string getNome() const;
	long getCode() const;
	void setNome(string nome);
	void setCod(long cod);
};



#endif /* SRC_VETERINARIO_H_ */
