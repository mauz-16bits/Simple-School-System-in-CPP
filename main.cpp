#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void adicionarAluno(vector<string>& nomes, vector<double>& notas) {
	string nome;
	double nota;

	cout << "Digite o nome do aluno: ";
	cin >> nome;

	cout << "Digite a nota do aluno: ";
	cin >> nota;

	nomes.push_back(nome);
	notas.push_back(nota);

	cout << "Aluno adicionado com sucesso!\n";
}

void exibirAlunos(const vector<string>& nomes, const vector<double>& notas) {
	if (nomes.empty()) {
		cout << "Nenhum aluno cadastrado.\n";
		return;
	}

	cout << "Lista de alunos e notas:\n";
	for (size_t i = 0; i < nomes.size(); ++i) {
		cout << nomes[i] << " - " << notas[i] << "\n";
	}
}

void exibirMedia(const vector<double>& notas) {
	if (notas.empty()) {
		cout << "Nenhuma nota cadastrada.\n";
		return;
	}

	double soma = 0;
	for (double nota : notas) {
		soma += nota;
	}

	double media = soma / notas.size();
	cout << "A mC)dia das notas C): " << media << "\n";
}

void exibirMaiorMenorNota(const vector<double>& notas) {
	if (notas.empty()) {
		cout << "Nenhuma nota cadastrada.\n";
		return;
	}

	double maior = numeric_limits<double>::min();
	double menor = numeric_limits<double>::max();

	for (double nota : notas) {
		if (nota > maior) {
			maior = nota;
		}
		if (nota < menor) {
			menor = nota;
		}
	}

	cout << "Maior nota: " << maior << "\n";
	cout << "Menor nota: " << menor << "\n";
}

int main() {
	vector<string> nomes;
	vector<double> notas;
	int opcao;

	do {
		cout << "\n1. Adicionar aluno e nota\n";
		cout << "2. Exibir lista de alunos e notas\n";
		cout << "3. Exibir mC)dia das notas\n";
		cout << "4. Exibir maior e menor nota\n";
		cout << "5. Sair\n";
		cout << "Escolha uma opC'C#o: ";
		cin >> opcao;

		switch (opcao) {
		case 1:
			adicionarAluno(nomes, notas);
			break;
		case 2:
			exibirAlunos(nomes, notas);
			break;
		case 3:
			exibirMedia(notas);
			break;
		case 4:
			exibirMaiorMenorNota(notas);
			break;
		case 5:
			cout << "Saindo...\n";
			break;
		default:
			cout << "OpC'C#o invC!lida. Tente novamente.\n";
		}
	} while (opcao != 5);

	return 0;
}
