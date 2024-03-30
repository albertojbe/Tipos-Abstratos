public class Pecas {
    String tipo;
    String cor;
    int linha;
    int coluna;

    public Pecas(String tipo, String cor, int linha, int coluna){
        this.tipo = tipo;
        this.cor = cor;
        this.linha = linha;
        this.coluna = coluna;
    }
    void imprimirInformacoes(){
        imprimir("Tipo da peça: " + this.tipo);
        imprimir("Cor da peça: " + this.cor);
        imprimir("Posição: " + this.linha + this.coluna);
    }
    void imprimir(String texto){
        System.out.println(texto);
    }
}
class Peao extends Pecas{
    public Peao(String tipo, String cor, int linha, int coluna){
        super(tipo, cor, linha, coluna);
    }
    void movimentarPeao(int novaLinha){
        if(verificarMovimento(novaLinha)){
            this.linha = novaLinha;
            imprimir("Movimento Realizado");
        } else{
            imprimir("Movimento Inválido");
        }
        
    }
    Boolean verificarMovimento(int novaLinha){
        if ((this.linha == 2 || this.linha == 7) && (novaLinha == 4 || novaLinha == 5)){
            return true;
        } else if (novaLinha - this.linha == 1 || this.linha - novaLinha == 1) {
            return true;
        } else{
            return false;
        }
    }
    void capturarPeca(int colunaCapturar, int linhaCapturar, String pecaCapturada){
        if(((colunaCapturar - this.coluna == 1) || (this.coluna - colunaCapturar == 1)) && ((linhaCapturar - this.linha == 1) || (this.linha - linhaCapturar == 1))){
            System.out.printf("A peça %s foi captura com sucesso na linha %d coluna %d!\n", pecaCapturada, linhaCapturar, colunaCapturar);
        } else{
            imprimir("Movimento inválido!");
        }
    }
}
