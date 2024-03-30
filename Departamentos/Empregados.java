import java.util.ArrayList;

public class Empregados {
    String nome;
    int id;
    String cargo;
    float salario;
    Departamento departamento;

    public Empregados(String nome, int id, String cargo, float salario) {
        this.nome = nome;
        this.id = id;
        this.cargo = cargo;
        this.salario = salario;
    }

    public void atualizarDados(String nome, String cargo, float salario) {
        this.nome = nome;
        this.cargo = cargo;
        this.salario = salario;
    }
    
    public void transferencia(Departamento departamento, Empregados empregado){
        this.departamento = departamento;
        departamento.adicionarEmpregado(empregado);
    }
    
    public void imprimirDados(){
        System.out.println("Nome: " + this.nome);
        System.out.println("ID: " + this.id);
        System.out.println("Cargo: " + this.cargo);
        System.out.println("Salário: " + this.salario);
        System.out.println("");
    }
    
    public void imprimirDepartamento(){
        departamento.informacoesDepartamento();
    }
}

public class Departamento {
    String nome;
    int id;
    String localizacao;
    ArrayList<Empregados> empregados;
    
    public Departamento(String nome, int id, String localizacao){
        this.nome = nome;
        this.id = id;
        this.localizacao = localizacao;
        this.empregados = new ArrayList<>();
    }
    
    public void adicionarEmpregado(Empregados empregado){
        this.empregados.add(empregado);
    }
    
    public void imprimirEmpregados(){
        System.out.printf("Lista de Empregados:\n\n");
        for(Empregados pessoa : empregados){
            pessoa.imprimirDados();
        }
    }
    
    public void removerEmpregado(Empregados empregado){
        this.empregados.remove(empregado);
    }
    
    public void informacoesDepartamento(){
        System.out.println("Nome: " + this.nome);
        System.out.println("ID: " + this.id);
        System.out.println("Localização: " + this.localizacao);
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        Empregados Alberto = new Empregados("Alberto", 18, "Atendente", 1300.00f);
        Empregados Carlos = new Empregados("Carlos", 18, "Atendente", 1300.00f);
        Departamento Recepcao = new Departamento("Recepção", 1, "Entrada");
        Carlos.transferencia(Recepcao, Carlos);
        Alberto.transferencia(Recepcao, Alberto);
        Recepcao.imprimirEmpregados();
        Alberto.imprimirDepartamento();
    }
}
