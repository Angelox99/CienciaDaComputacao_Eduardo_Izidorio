public class Atualizador{
   
    private double saldototal=0;
    private double selic;

    public Atualizador(double selic){
        this.selic= selic;
    }
    
    public void roda(Conta c){
        System.out.println("saldo anterior : "+c.getSaldo());
        c.Atualiza(this.selic);
        System.out.println("saldo novo : "+c.getSaldo());
        saldototal +=  c.getSaldo();    
    }

    public double getSaldoTotal(){
        return this.saldototal;
    }

}