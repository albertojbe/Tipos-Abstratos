public class Biblioteca {
    private String tituloLivro;
    private String autorLivro;
    private int anoLivro;
    private int numeroCopias;

    public void inicializar(String titulo, String autor, int ano, int copias) {
        this.tituloLivro = titulo;
        this.autorLivro = autor;
        this.anoLivro = ano;
        this.numeroCopias = copias;
    }

    public int emprestarCopias() {
        return --this.numeroCopias;
    }

    public int devolverCopias() {
        return ++this.numeroCopias;
    }

    public void verificarCopias() {
        if (this.numeroCopias > 0) {
            System.out.printf("O número de cópias é: %d.\n", this.numeroCopias);
        } else {
            System.out.println("Não há cópias disponíveis.");
        }
    }

    void imprimir(String formato, Object... args) {
        System.out.printf(formato, args);
    }

    public void imprimirDetalhes() {
        imprimir("Título: %s\n", this.tituloLivro);
        imprimir("Autor: %s\n", this.autorLivro);
        imprimir("Ano de lançamento: %d\n", this.anoLivro);
        imprimir("Número de cópias: %d\n", this.numeroCopias);
    }

    public static void main(String[] args) {
        Biblioteca livroUm = new Biblioteca();
        livroUm.inicializar("O Festim dos Corvos", "George Martin", 2005, 5);
        livroUm.imprimirDetalhes();
    }
}
