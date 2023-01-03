public abstract class Conta{

    protected double saldo;
    private String nome;

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSaldo(){
        return this.saldo;
    }
    
    abstract public void Deposita(double valor) throws ValorInvalidoException;
    abstract public void Atualiza(double taxa);
    
    public void Saca(double valor){
        if(valor<this.saldo){
        this.saldo=-valor;
        }
        else{
            System.out.println("Não é possivel sacar essa quantia. Saldo disponivel: "+this.saldo);
        }
    }
    
    
    
}