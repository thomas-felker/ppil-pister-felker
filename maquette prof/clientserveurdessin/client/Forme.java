package clientserveurdessin.client;

import java.io.IOException;
import java.net.UnknownHostException;

/**
 * Hiérarchie simplifiée de formes en 2D
 * 
 * */
public abstract class Forme
{
public void dessiner()
{
try
{
ClientDessin clientDessin = new ClientDessin("127.0.0.1",8091);

dessiner1(clientDessin);
}
catch (UnknownHostException e)
{
System.err.println("le dessinateur n'est pas disponible : " + e);
}
catch (IOException e)
{
System.err.println("le dessinateur a été interrompu : " + e);
}
}
abstract  void dessiner1(ClientDessin clientDessin);

}



