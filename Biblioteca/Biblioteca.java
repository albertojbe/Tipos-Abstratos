package Biblioteca;

public class Biblioteca{
    private String tituloLivro;
    private String autorLivro;
    private int anoLivro;
    private int numeroCopias;

    public Biblioteca(String titulo, String autor, int ano, int copias){
        this.tituloLivro = titulo;
        this.autorLivro = autor;
        this.anoLivro = ano;
        this.numeroCopias = copias;
    }
}
