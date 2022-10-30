# berenice-pt3
Estudo de caso projeto 3: Sistema da  Berenice - Vendendo ++
Introdução: As informações aqui contidas fazem parte do processo de desenvolvimento do projeto mensal intitulado, Sistema de Persistência de dados em Linguagem C.
Portanto, devem ser analisadas e utilizadas como fonte de dados para planejamento e implementação do mesmo.
Período de execução: 11/10/2022 a 08/11/2022
Berenice quer uma melhoria dos sistema anterior que possua agora as seguintes funcionalidades:
Atualizar o menu para a escolha das seguintes opções através de funções:
Produtos;
Vendas;
Sair.

Ao selecionar a opção de “Produtos”:
Exibir um submenu com as seguintes opções:
Exibir;
Cadastrar;
Atualizar;
Excluir;
Salvar;
Ler;
Voltar;
Ler a opção do submenu desejada, e realizar ações abaixo:
Se inválida, exibir a mensagem "Opção inválida" e exibir novamente o submenu de produtos, bem como possibilitar novamente a escolha da opção;
Se válida, executar a função da respectiva opção selecionada descrita abaixo.
Se for selecionada a opção "Exibir", chame a função do trabalho anterior que visualizava o estoque atualizada para a estrutura da nova versão. Exemplo de produtos cadastrados: 
Item (código)
Nome do Item
Valor (Unidade)
Estoque
18745
Pão de Forma
R$ 7,50
0
45462
Pão de Centeio
R$ 8,69
5
34654
Broa de Milho
R$ 5,00
2
40
Sonho
R$ 4,50
3
5000
Tubaína
R$ 3.25
0


Se for selecionada a opção "Cadastrar":
Solicitar a quantidade de novos produtos que Berenice deseja cadastrar, com as seguintes condições:
Manter os produtos já cadastrados se houverem;
Adicionar ao final do vetor os novos produtos;
Dica: Usar vetor de ponteiros para uma struct;
Solicitar que sejam digitados os seguintes dados para cada novo produto a ser cadastrado:
Código do Item (Valor inteiro sem sinal com 64 bits diferente de zero, único, portanto não pode já existir no cadastro);
Nome do Item (String com até 25 caracteres, não podendo ser vazio ou somente com espaços);
Preço Unitário do item (Valor decimal maior ou igual a zero);
Quantidade do item em estoque (Valor inteiro maior ou igual a zero);
Validar se os dados solicitados atendem às condições entre parênteses, e em caso afirmativo inserir o novo produto nos produtos cadastrados, e caso contrário, solicitar que sejam digitados novamente os dados até que seja inserido corretamente.
Dica: Usar como base para esta opção a antiga opção de cadastrar estoque e suas validações, as quais podem ser implementadas igual a versão anterior.
Se for selecionada a opção "Atualizar":
Exibir os produtos e solicitar ao usuário o código do produto a ser atualizado;
Procurar nos produtos já cadastrados se o código digitado está presente:
Se estiver presente, possibilitar a atualização da quantidade e valor unitário do produto encontrado, e uma confirmação da alteração exibindo o antes e depois;
Se não estiver presente, exibir a mensagem "Produto não encontrado" e retornar ao submenu de produtos.
Se for selecionada a opção "Excluir":
Exibir os produtos e solicitar ao usuário o código do produto a ser excluído;
Procurar nos produtos já cadastrados se o código digitado está presente:
Se estiver presente, apresentar o produto e confirmar se o usuário deseja realmente excluir o produto;
Se não estiver presente, exibir a mensagem "Produto não encontrado" e retornar ao submenu de produtos.
Se for selecionada a opção "Salvar", você deverá salvar os produtos cadastrados no arquivo "produtos.txt" com o seguinte formato:

quantidade_produtos
código1
nome_produto1
valor_unitário1
quant_estoque1
quant_vendida1
código2
nome_produto2
valor_unitário2
quant_estoque2
quant_vendida2
…
códigoN
nome_produtoN
valor_unitárioN
quant_estoqueN
quant_vendidaN

Na primeira linha do arquivo, estará o número de produtos que serão salvos;
Na linha seguinte em diante serão impressos os dados dos produtos separados por uma nova linha;
Exemplo de arquivo contendo 3 dos produtos mencionados no item 2.3:
3
18745
Pão de Forma
7.50
0
0
45462
Pão de Centeio
8.69
5
0
34654
Broa de Milho
5.00
2

Se for selecionada a opção "Ler", a lista atual de produtos deverá ser apagada se existir e em seguida deverá ser lido os produtos do arquivo salvo anteriormente.
Se for selecionado a opção "Voltar", retornar para o menu principal.

Se for selecionada a opção "Vendas":
Exibir um sub-menu com as seguintes opções:
Realizar venda;
Relatório de vendas;
Voltar;
Ler a opção do submenu desejada, e realizar ações abaixo:
Se inválida, exibir a mensagem "Opção inválida" e exibir novamente o submenu de venda, bem como possibilitar novamente a escolha da opção;
Se válida, executar a função da respectiva opção selecionada descrita abaixo.
Ao selecionar a opção “Realizar Venda”, fazer a venda igual a implementação já realizada anteriormente com as novas estruturas.
Ao selecionar a opção "Relatório de Vendas", exibir os produtos com a quantidade atual em estoque e sua respectiva quantidade de itens vendidos;
Dica: Use a mesma função de exibir produtos com um parâmetro para exibir ou não o número de itens já vendidos.
Se for selecionado a opção "Voltar", retornar para o menu principal.

Ao selecionar a opção “Sair” finalizar o programa;
Se nenhuma das opções for válida, exibir a mensagem "Opção inválida!" e  novamente o menu principal, bem como ler novamente o código da opção a ser selecionada.
Pontuação dos itens do trabalho:

Item
Descrição Abreviada
Valor
1,  4 e 5
Menu Principal
5
2.1, 2.2 e 2.9
Submenu Produtos
10
2.3
Exibir Produtos
10
2.4
Cadastrar Produtos
25
2.5
Atualizar Produtos
5
2.6
Excluir Produtos
5
2.7
Salvar Produtos
7,5
2.8
Ler Produtos
7,5
3.1, 3.2 e 3.5
Submenu Vendas
5
3.3
Realizar Venda
15
3.4
Relatório de vendas
5


Desafios (5 pontos adicionais para cada):
Ler/Salvar os produtos em arquivo no formato binário em vez de texto;
Salvar em arquivo texto a lista de itens vendidos após finalizar a venda devendo o nome do arquivo ser no formato "Ano-Mes-Dia_Hora-Minuto-Segundo.txt";
Atualização do Trello com as novas tarefas - A qual deve conter ao menos duas atualizações semanais, feitas por usuários diferentes. 
