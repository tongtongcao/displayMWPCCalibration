#include <vector>
#include <string>
#include <sstream>
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TROOT.h"
#include "TLegend.h"
using namespace std;


void compare(){
 gStyle->SetOptStat(0000);
 gStyle->SetOptFit(0000);
gROOT->ForceStyle();

 string str[7]={"3157","3397","3399","3779","4142","4272","4273"};

 TFile *file[7];
 TH1D *MwpcC2YL[7][16],*MwpcC2YR[7][16],*MwpcC3YL[7][16],*MwpcC3YR[7][16],*MwpcC4YL[7][16],*MwpcC4YR[7][16];
 TH1D *MwpcC2XL[7][56],*MwpcC2XR[7][56],*MwpcC3XL[7][64],*MwpcC3XR[7][64],*MwpcC4XL[7][72],*MwpcC4XR[7][72];

 ostringstream sstr;
 for(int i=0;i<7;i++){
  sstr<<"/home/caot/trek-e36/dataRaw/histos/MWPC/pedestal/histo_run"<<str[i]<<".root";
  file[i]=new TFile(sstr.str().c_str());
  sstr.str("");
  for(int j=0;j<16;j++){
   sstr<<"MwpcC2YL_St"<<j;
   MwpcC2YL[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());      
   sstr.str("");

   sstr<<"MwpcC2YR_St"<<j;
   MwpcC2YR[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC3YL_St"<<j;
   MwpcC3YL[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC3YR_St"<<j;
   MwpcC3YR[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC4YL_St"<<j;
   MwpcC4YL[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC4YR_St"<<j;
   MwpcC4YR[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");
  }   

  for(int j=0;j<56;j++){
   sstr<<"MwpcC2XL_St"<<j;
   MwpcC2XL[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC2XR_St"<<j;
   MwpcC2XR[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");
  }

  for(int j=0;j<64;j++){
   sstr<<"MwpcC3XL_St"<<j;
   MwpcC3XL[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC3XR_St"<<j;
   MwpcC3XR[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");
  }

  for(int j=0;j<72;j++){
   sstr<<"MwpcC4XL_St"<<j;
   MwpcC4XL[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");

   sstr<<"MwpcC4XR_St"<<j;
   MwpcC4XR[i][j]=(TH1D*)file[i]->Get(sstr.str().c_str());
   sstr.str("");
  }
 }

 TLegend *legend=new TLegend(0.7,0.5,0.9,0.9);
 for(int i=0;i<7;i++){
  sstr<<"Run"<<str[i];
  legend->AddEntry(MwpcC2YL[i][0],sstr.str().c_str(),"l");
  sstr.str("");
 }

 TCanvas *canv_MwpcC2YL[16],*canv_MwpcC2YR[16],*canv_MwpcC3YL[16],*canv_MwpcC3YR[16],*canv_MwpcC4YL[16],*canv_MwpcC4YR[16];
 TCanvas *canv_MwpcC2XL[56],*canv_MwpcC2XR[56],*canv_MwpcC3XL[64],*canv_MwpcC3XR[64],*canv_MwpcC4XL[64],*canv_MwpcC4XR[64];
 for(int j=0;j<16;j++){
  sstr<<"MwpcC2YL_St"<<j;
  canv_MwpcC2YL[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
  sstr<<"MwpcC2YR_St"<<j;
  canv_MwpcC2YR[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");

  sstr<<"MwpcC3YL_St"<<j;
  canv_MwpcC3YL[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
  sstr<<"MwpcC3YR_St"<<j;
  canv_MwpcC3YR[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");

  sstr<<"MwpcC4YL_St"<<j;
  canv_MwpcC4YL[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
  sstr<<"MwpcC4YR_St"<<j;
  canv_MwpcC4YR[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
 }

 for(int j=0;j<56;j++){
  sstr<<"MwpcC2XL_St"<<j;
  canv_MwpcC2XL[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
  sstr<<"MwpcC2XR_St"<<j;
  canv_MwpcC2XR[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
 }

 for(int j=0;j<64;j++){
  sstr<<"MwpcC3XL_St"<<j;
  canv_MwpcC3XL[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
  sstr<<"MwpcC3XR_St"<<j;
  canv_MwpcC3XR[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
 }

 for(int j=0;j<72;j++){
  sstr<<"MwpcC4XL_St"<<j;
  canv_MwpcC4XL[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
  sstr<<"MwpcC4XR_St"<<j;
  canv_MwpcC4XR[j]=new TCanvas(sstr.str().c_str(),sstr.str().c_str());
  sstr.str("");
 }

 for(int j=0;j<16;j++){
  canv_MwpcC2YL[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC2YL[i][j]->SetLineColor(i+2);
    MwpcC2YL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2YL[i][j]->Draw();
   }
   else{
    MwpcC2YL[i][j]->SetLineColor(i+2);
    MwpcC2YL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2YL[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC2YL_St"<<j<<".png";
  canv_MwpcC2YL[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC2YL[j]->Close();

  canv_MwpcC2YR[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC2YR[i][j]->SetLineColor(i+2);
    MwpcC2YR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2YR[i][j]->Draw();
   }
   else{
    MwpcC2YR[i][j]->SetLineColor(i+2);
    MwpcC2YR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2YR[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC2YR_St"<<j<<".png";
  canv_MwpcC2YR[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC2YR[j]->Close();

  canv_MwpcC3YL[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC3YL[i][j]->SetLineColor(i+2);
    MwpcC3YL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3YL[i][j]->Draw();
   }
   else{
    MwpcC3YL[i][j]->SetLineColor(i+2);
    MwpcC3YL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3YL[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC3YL_St"<<j<<".png";
  canv_MwpcC3YL[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC3YL[j]->Close();

  canv_MwpcC3YR[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC3YR[i][j]->SetLineColor(i+2);
    MwpcC3YR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3YR[i][j]->Draw();
   }
   else{
    MwpcC3YR[i][j]->SetLineColor(i+2);
    MwpcC3YR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3YR[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC3YR_St"<<j<<".png";
  canv_MwpcC3YR[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC3YR[j]->Close();

  canv_MwpcC4YL[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC4YL[i][j]->SetLineColor(i+2);
    MwpcC4YL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4YL[i][j]->Draw();
   }
   else{
    MwpcC4YL[i][j]->SetLineColor(i+2);
    MwpcC4YL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4YL[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC4YL_St"<<j<<".png";
  canv_MwpcC4YL[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC4YL[j]->Close();

  canv_MwpcC4YR[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC4YR[i][j]->SetLineColor(i+2);
    MwpcC4YR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4YR[i][j]->Draw();
   }
   else{
    MwpcC4YR[i][j]->SetLineColor(i+2);
    MwpcC4YR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4YR[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC4YR_St"<<j<<".png";
  canv_MwpcC4YR[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC4YR[j]->Close();
 }

 for(int j=0;j<56;j++){
  canv_MwpcC2XL[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC2XL[i][j]->SetLineColor(i+2);
    MwpcC2XL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2XL[i][j]->Draw();
   }
   else{
    MwpcC2XL[i][j]->SetLineColor(i+2);
    MwpcC2XL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2XL[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC2XL_St"<<j<<".png";
  canv_MwpcC2XL[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC2XL[j]->Close();

  canv_MwpcC2XR[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC2XR[i][j]->SetLineColor(i+2);
    MwpcC2XR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2XR[i][j]->Draw();
   }
   else{
    MwpcC2XR[i][j]->SetLineColor(i+2);
    MwpcC2XR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC2XR[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC2XR_St"<<j<<".png";
  canv_MwpcC2XR[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC2XR[j]->Close();
 }

 for(int j=0;j<64;j++){
  canv_MwpcC3XL[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC3XL[i][j]->SetLineColor(i+2);
    MwpcC3XL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3XL[i][j]->Draw();
   }
   else{
    MwpcC3XL[i][j]->SetLineColor(i+2);
    MwpcC3XL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3XL[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC3XL_St"<<j<<".png";
  canv_MwpcC3XL[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC3XL[j]->Close();

  canv_MwpcC3XR[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC3XR[i][j]->SetLineColor(i+2);
    MwpcC3XR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3XR[i][j]->Draw();
   }
   else{
    MwpcC3XR[i][j]->SetLineColor(i+2);
    MwpcC3XR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC3XR[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC3XR_St"<<j<<".png";
  canv_MwpcC3XR[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC3XR[j]->Close();
 }

 for(int j=0;j<72;j++){
  canv_MwpcC4XL[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC4XL[i][j]->SetLineColor(i+2);
    MwpcC4XL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4XL[i][j]->Draw();
   }
   else{
    MwpcC4XL[i][j]->SetLineColor(i+2);
    MwpcC4XL[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4XL[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC4XL_St"<<j<<".png";
  canv_MwpcC4XL[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC4XL[j]->Close();

  canv_MwpcC4XR[j]->cd();
  for(int i=0;i<7;i++){
   if(i==0){
    MwpcC4XR[i][j]->SetLineColor(i+2);
    MwpcC4XR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4XR[i][j]->Draw();
   }
   else{
    MwpcC4XR[i][j]->SetLineColor(i+2);
    MwpcC4XR[i][j]->GetFunction("gaus")->SetLineColor(i+2);
    MwpcC4XR[i][j]->Draw("same");
   }
  }
  legend->Draw();
  sstr<<"MwpcC4XR_St"<<j<<".png";
  canv_MwpcC4XR[j]->SaveAs(sstr.str().c_str());
  sstr.str("");
  canv_MwpcC4XR[j]->Close();
 }
}

