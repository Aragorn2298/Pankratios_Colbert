/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hashtaggerjava;
import twitter4j.*;
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;
import javax.swing.JOptionPane;
/**
 *
 * @author xblao
 */
public class HashtaggerJava {

    /**
     * @param args the command line arguments
     */
    private static void storeJSON(String rawJSON, String fileName) throws IOException {
        FileOutputStream fos = null;
        OutputStreamWriter osw = null;
        BufferedWriter bw = null;
        try {
            fos = new FileOutputStream(fileName);
            osw = new OutputStreamWriter(fos, "UTF-8");
            bw = new BufferedWriter(osw);
            bw.write(rawJSON);
            bw.flush();
        } finally {
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException ignore) {
                }
            }
            if (osw != null) {
                try {
                    osw.close();
                } catch (IOException ignore) {
                }
            }
            if (fos != null) {
                try {
                    fos.close();
                } catch (IOException ignore) {
                }
            }
        }
    }
    
    public static void main(String[] args) {
        String date = new SimpleDateFormat("yyyyMMdd_HHmmss").format(Calendar.getInstance().getTime());
        
        String queryString;
        queryString = args[0];
        
        System.out.print("Busqueda: " + args[0]);
        
        String folderName = queryString+date;
        
        try {
            Twitter twitter = TwitterFactory.getSingleton();
            Query query = new Query(queryString);
            query.count(100);
            QueryResult result;
                
            result = twitter.search(query);
            List<Status> tweets = result.getTweets();
            new File("Tweets/"+folderName).mkdir();
            
            for(int i=0;i<100;i++){
                Status tweet = tweets.get(i);

                String rawJSON = TwitterObjectFactory.getRawJSON(tweet);
                String fileName = "Tweets/"+folderName+ "/" + queryString + tweet.getId() + "_" + date + ".json";
                try{
                    storeJSON(rawJSON, fileName);
                }catch(IOException e){
                    JOptionPane.showMessageDialog(null, "Failed to store Json");
                }
            }
        } catch (TwitterException te) {
            te.printStackTrace();
            System.out.println("Failed to search tweets: " + te.getMessage());
            System.exit(-1);
        }
    //return folderName;
    }
}
