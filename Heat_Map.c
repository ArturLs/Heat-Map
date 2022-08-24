void g1()
{

//////////////////////////////////////////////////////////////////
/////////////////////// Values///////////////////////////////////
///////////////////////////////////////////////////////////////// 



int events = 1700;



//////////////////////////////////////////////////////////////////
/////////////////////// PHOTONS///////////////////////////////////
///////////////////////////////////////////////////////////////// 

 
    FILE *myFile;
    myFile = fopen("P", "r");


   int p[events];
   int i;

   if (myFile == NULL){
      printf("Error Reading File\n");
     exit (0);
   }

      for (i = 0; i < 1700; i++){
         fscanf(myFile, "%d", &p[i] );
    }
       fclose(myFile);
       
   
//////////////////////////////////////////////////////////////////
///////////////////// Y POSITION/////////////////////////////////
///////////////////////////////////////////////////////////////// 
 
 
    FILE *MY;
    MY = fopen("Y", "r");


   float y[events];

   if (myFile == NULL){
      printf("Error Reading File\n");
     exit (0);
   }

      for (i = 0; i < 1700; i++){
         fscanf(myFile, "%e", &y[i] );
    }
       fclose(MY);
       
       
       
//////////////////////////////////////////////////////////////////
///////////////////// X  POSITION/////////////////////////////////
///////////////////////////////////////////////////////////////// 


    FILE *mw;
    mw = fopen("X", "r");


   float x[events];

   if (myFile == NULL){
      printf("Error Reading File\n");
     exit (0);
   }

      for (i = 0; i < 1700; i++){
         fscanf(myFile, "%e", &x[i] );
    }
       fclose(mw);
   

//////////////////////////////////////////////////////////////////
//////////////////////// PLOTS////////////////////////////////////
///////////////////////////////////////////////////////////////// 
 


       TCanvas *c1 = new TCanvas();
    
        
    TH2F *hist = new TH2F("Data", "Heat map", 10, -140, 140, 10, -140, 140);
    gStyle->SetPalette(55);
    // 53 other colour
    

      for(int i = 0; i < events+1; i++){
        
        if(p[i] == 0){
           hist->Fill(x[i],y[i]);

    }else{

        for(float k = 0; k<p[i]; k++){
            hist->Fill(x[i],y[i]);
        
}

}    
    }
   
    
    
    hist->GetXaxis()->SetTitle("x [mm]");
    hist->GetYaxis()->SetTitle("y [mm]");
    hist->GetZaxis()->SetTitle("Photons");
    hist->Fill(0.,0.,0.);
    hist->Draw("COLZ");
}






