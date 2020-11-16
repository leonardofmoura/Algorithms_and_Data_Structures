# faculty-management
AEDA project 2018/19

## Install
To install, go inside the project's directory and run the following command:
- `make` (`make install` will also work)


To delete the compilation files, run `make clean`


## Tema 7 – Gestão de Faculdade
### Parte 1
Pretende-se guardar informação sobre uma faculdade, seus departamentos, cursos, 
disciplinas, estudantes, docentes e funcionários. 
- A faculdade é composta por um conjunto de departamentos. Interessa saber os 
códigos e nomes dos departamentos, morada, telefone e diretores de cada 
departamento.
- Cada departamento da faculdade tem um conjunto de cursos que podem ser de 
três tipos (licenciaturas, mestrados e mestrados integrados). 
- Para cada curso interessa saber o código, nome, plano curricular (disciplinas 
e respetivos dados) e diretor de curso. 
- Cada disciplina, tem um código, nome (em português e inglês), é lecionada por 
um conjunto de docentes, sendo um o seu regente (responsável), tem um conjunto 
de alunos e tem ainda o ano, ECTS e carga horária.
- Existem na universidade funcionários não docentes, alunos e docentes. Todos 
eles têm nome, morada, telefone, data de nascimento e código. 
- Os alunos têm também o curso em que estão matriculados, o conjunto de 
disciplinas a que se inscreveram em cada ano letivo e respetivas 
notas/resultados. 
- Os docentes têm também o conjunto de disciplinas que lecionam, categoria, 
no contribuinte e o salário respetivo. 
- Para os funcionários e docentes interessa saber a área de trabalho, no 
contribuinte e o salário.
- O sistema deve permitir a consulta do conjunto de estudantes e respetivos 
dados incluindo a média atual de curso, conjunto de funcionários (docentes e 
não docentes) e respetivos dados, e plano curricular de cada curso com as 
respetivas disciplinas (nota: esta enumeração de listagens a implementar não 
é exaustiva).
Implemente também outras funcionalidades que considere relevantes, para além 
dos requisitos globais enunciados.

### Parte 2
Complemente o sistema já implementado com as seguintes funcionalidades:
- Pretende-se adicionar ao sistema de gestão de faculdades um registo de todos 
os seus alunos e respetivos cursos. Para tal, guarde numa árvore binária de 
pesquisa os alunos da faculdade ordenados pelo respetivo curso e em caso de 
pertencerem ao mesmo curso, ordenados por ordem alfabética.
- Considere que na faculdade são atribuídas bolsas aos estudantes em períodos 
regulares. As bolsas são atribuídas aos estudantes de acordo com a respetiva 
média de curso, ano curricular em que estão inscritos e idade. De forma a 
facilitar esta atribuição, use uma fila de prioridade para guardar os 
estudantes ordenada pela respetiva média de curso (arredondada ao inteiro 
mais próximo). Em caso de igualdade considere que as bolsas são atribuídas 
aos candidatos que estejam num ano curricular superior e entre estes aos 
candidatos mais novos, devendo a fila de prioridade respeitar esta ordem. 
Implemente também a atualização da fila sempre que um estudante tiver uma nova 
nota atribuída que altere a sua média de curso.
- A faculdade mantém um registo de todos os seus funcionários (atuais e 
antigos) numa tabela de dispersão. A manutenção do registo de funcionários 
antigos da empresa justifica-se porque, no caso de necessidade de contratação 
urgente de um funcionário, a faculdade tem como preferência a contratação de 
funcionários já conhecidos e que tenham tido uma colaboração de trabalho longa 
com a faculdade.
Implemente também outras funcionalidades que considere relevantes, para além 
dos requisitos globais enunciados.