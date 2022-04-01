#include <vector>
#include <string>
#include <sstream>
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TROOT.h"
#include "TLegend.h"
using namespace std;

void compare_sigma(){
 gStyle->SetOptStat(0000);
 gStyle->SetOptFit(0000);
 gROOT->ForceStyle();

 string str[7]={"3157","3397","3399","3779","4142","4272","4273"};
 TFile *file[7];
 TTree *tree[7];

 double sigmaC2YL[7][16],sigmaC2YR[7][16],sigmaC3YL[7][16],sigmaC3YR[7][16],sigmaC4YL[7][16],sigmaC4YR[7][16];
 double sigmaC2XL[7][56],sigmaC2XR[7][56],sigmaC3XL[7][64],sigmaC3XR[7][64],sigmaC4XL[7][72],sigmaC4XR[7][72];
 double sigmaErrC2YL[7][16],sigmaErrC2YR[7][16],sigmaErrC3YL[7][16],sigmaErrC3YR[7][16],sigmaErrC4YL[7][16],sigmaErrC4YR[7][16];
 double sigmaErrC2XL[7][56],sigmaErrC2XR[7][56],sigmaErrC3XL[7][64],sigmaErrC3XR[7][64],sigmaErrC4XL[7][72],sigmaErrC4XR[7][72];


 ostringstream sstr;
 for(int i=0;i<7;i++){
  sstr<<"/home/caot/trek-e36/analysis/MWPC/pedestal/Run"<<str[i]<<"/pedestal.root";
cout<<sstr.str()<<endl;
  file[i]=new TFile(sstr.str().c_str());
  sstr.str("");
  tree[i]=(TTree*)file[i]->Get("pedestal");

  tree[i]->SetBranchAddress("sigmaC2XL",sigmaC2XL[i]);
  tree[i]->SetBranchAddress("sigmaC2XR",sigmaC2XR[i]);
  tree[i]->SetBranchAddress("sigmaC3XL",sigmaC3XL[i]);
  tree[i]->SetBranchAddress("sigmaC3XR",sigmaC3XR[i]);
  tree[i]->SetBranchAddress("sigmaC4XL",sigmaC4XL[i]);
  tree[i]->SetBranchAddress("sigmaC4XR",sigmaC4XR[i]);

  tree[i]->SetBranchAddress("sigmaC2YL",sigmaC2YL[i]);
  tree[i]->SetBranchAddress("sigmaC2YR",sigmaC2YR[i]);
  tree[i]->SetBranchAddress("sigmaC3YL",sigmaC3YL[i]);
  tree[i]->SetBranchAddress("sigmaC3YR",sigmaC3YR[i]);
  tree[i]->SetBranchAddress("sigmaC4YL",sigmaC4YL[i]);
  tree[i]->SetBranchAddress("sigmaC4YR",sigmaC4YR[i]);

  tree[i]->SetBranchAddress("sigmaErrC2XL",sigmaErrC2XL[i]);
  tree[i]->SetBranchAddress("sigmaErrC2XR",sigmaErrC2XR[i]);
  tree[i]->SetBranchAddress("sigmaErrC3XL",sigmaErrC3XL[i]);
  tree[i]->SetBranchAddress("sigmaErrC3XR",sigmaErrC3XR[i]);
  tree[i]->SetBranchAddress("sigmaErrC4XL",sigmaErrC4XL[i]);
  tree[i]->SetBranchAddress("sigmaErrC4XR",sigmaErrC4XR[i]);

  tree[i]->SetBranchAddress("sigmaErrC2YL",sigmaErrC2YL[i]);
  tree[i]->SetBranchAddress("sigmaErrC2YR",sigmaErrC2YR[i]);
  tree[i]->SetBranchAddress("sigmaErrC3YL",sigmaErrC3YL[i]);
  tree[i]->SetBranchAddress("sigmaErrC3YR",sigmaErrC3YR[i]);
  tree[i]->SetBranchAddress("sigmaErrC4YL",sigmaErrC4YL[i]);
  tree[i]->SetBranchAddress("sigmaErrC4YR",sigmaErrC4YR[i]);

  tree[i]->GetEntry(0);
 } 

 TH1D *hist_sigmaC2YL[7],*hist_sigmaC2YR[7],*hist_sigmaC3YL[7],*hist_sigmaC3YR[7],*hist_sigmaC4YL[7],*hist_sigmaC4YR[7];
 TH1D *hist_sigmaC2XL[7],*hist_sigmaC2XR[7],*hist_sigmaC3XL[7],*hist_sigmaC3XR[7],*hist_sigmaC4XL[7],*hist_sigmaC4XR[7];
 ostringstream name,title;
 for(int i=0;i<7;i++){
  name<<"pedestal of MwpcC2YL for Run"<<str[i];
  title<<"pedestal of MwpcC2YL;Strip;Pedestal";
  hist_sigmaC2YL[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_sigmaC2YL[i]->SetBinContent(j+1,sigmaC2YL[i][j]);
   hist_sigmaC2YL[i]->SetBinError(j+1,sigmaErrC2YL[i][j]);
  }

  name<<"pedestal of MwpcC2YR for Run"<<str[i];
  title<<"pedestal of MwpcC2YR;Strip;Pedestal";
  hist_sigmaC2YR[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_sigmaC2YR[i]->SetBinContent(j+1,sigmaC2YR[i][j]);
   hist_sigmaC2YR[i]->SetBinError(j+1,sigmaErrC2YR[i][j]);
  }

  name<<"pedestal of MwpcC3YL for Run"<<str[i];
  title<<"pedestal of MwpcC3YL;Strip;Pedestal";
  hist_sigmaC3YL[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_sigmaC3YL[i]->SetBinContent(j+1,sigmaC3YL[i][j]);
   hist_sigmaC3YL[i]->SetBinError(j+1,sigmaErrC3YL[i][j]);
  }

  name<<"pedestal of MwpcC3YR for Run"<<str[i];
  title<<"pedestal of MwpcC3YR;Strip;Pedestal";
  hist_sigmaC3YR[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_sigmaC3YR[i]->SetBinContent(j+1,sigmaC3YR[i][j]);
   hist_sigmaC3YR[i]->SetBinError(j+1,sigmaErrC3YR[i][j]);
  }


  name<<"pedestal of MwpcC4YL for Run"<<str[i];
  title<<"pedestal of MwpcC4YL;Strip;Pedestal";
  hist_sigmaC4YL[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_sigmaC4YL[i]->SetBinContent(j+1,sigmaC4YL[i][j]);
   hist_sigmaC4YL[i]->SetBinError(j+1,sigmaErrC4YL[i][j]);
  }

  name<<"pedestal of MwpcC4YR for Run"<<str[i];
  title<<"pedestal of MwpcC4YR;Strip;Pedestal";
  hist_sigmaC4YR[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_sigmaC4YR[i]->SetBinContent(j+1,sigmaC4YR[i][j]);
   hist_sigmaC4YR[i]->SetBinError(j+1,sigmaErrC4YR[i][j]);
  }

  name<<"pedestal of MwpcC2XL for Run"<<str[i];
  title<<"pedestal of MwpcC2XL;Strip;Pedestal";
  hist_sigmaC2XL[i]=new TH1D(name.str().c_str(),title.str().c_str(),56,-0.5,55.5);
  name.str("");
  title.str("");
  for(int j=0;j<56;j++){
   hist_sigmaC2XL[i]->SetBinContent(j+1,sigmaC2XL[i][j]);
   hist_sigmaC2XL[i]->SetBinError(j+1,sigmaErrC2XL[i][j]);
  }

  name<<"pedestal of MwpcC2XR for Run"<<str[i];
  title<<"pedestal of MwpcC2XR;Strip;Pedestal";
  hist_sigmaC2XR[i]=new TH1D(name.str().c_str(),title.str().c_str(),56,-0.5,55.5);
  name.str("");
  title.str("");
  for(int j=0;j<56;j++){
   hist_sigmaC2XR[i]->SetBinContent(j+1,sigmaC2XR[i][j]);
   hist_sigmaC2XR[i]->SetBinError(j+1,sigmaErrC2XR[i][j]);
  }

  name<<"pedestal of MwpcC3XL for Run"<<str[i];
  title<<"pedestal of MwpcC3XL;Strip;Pedestal";
  hist_sigmaC3XL[i]=new TH1D(name.str().c_str(),title.str().c_str(),64,-0.5,63.5);
  name.str("");
  title.str("");
  for(int j=0;j<64;j++){
   hist_sigmaC3XL[i]->SetBinContent(j+1,sigmaC3XL[i][j]);
   hist_sigmaC3XL[i]->SetBinError(j+1,sigmaErrC3XL[i][j]);
  }

  name<<"pedestal of MwpcC3XR for Run"<<str[i];
  title<<"pedestal of MwpcC3XR;Strip;Pedestal";
  hist_sigmaC3XR[i]=new TH1D(name.str().c_str(),title.str().c_str(),64,-0.5,63.5);
  name.str("");
  title.str("");
  for(int j=0;j<64;j++){
   hist_sigmaC3XR[i]->SetBinContent(j+1,sigmaC3XR[i][j]);
   hist_sigmaC3XR[i]->SetBinError(j+1,sigmaErrC3XR[i][j]);
  }

  name<<"pedestal of MwpcC4XL for Run"<<str[i];
  title<<"pedestal of MwpcC4XL;Strip;Pedestal";
  hist_sigmaC4XL[i]=new TH1D(name.str().c_str(),title.str().c_str(),72,-0.5,71.5);
  name.str("");
  title.str("");
  for(int j=0;j<72;j++){
   hist_sigmaC4XL[i]->SetBinContent(j+1,sigmaC4XL[i][j]);
   hist_sigmaC4XL[i]->SetBinError(j+1,sigmaErrC4XL[i][j]);
  }

  name<<"pedestal of MwpcC4XR for Run"<<str[i];
  title<<"pedestal of MwpcC4XR;Strip;Pedestal";
  hist_sigmaC4XR[i]=new TH1D(name.str().c_str(),title.str().c_str(),72,-0.5,71.5);
  name.str("");
  title.str("");
  for(int j=0;j<72;j++){
   hist_sigmaC4XR[i]->SetBinContent(j+1,sigmaC4XR[i][j]);
   hist_sigmaC4XR[i]->SetBinError(j+1,sigmaErrC4XR[i][j]);
  }
 }

 TLegend *legend=new TLegend(0.7,0.6,0.9,0.9);
 for(int i=0;i<7;i++){
  sstr<<"Run"<<str[i];
  legend->AddEntry(hist_sigmaC2XL[i],sstr.str().c_str(),"l");
  sstr.str("");
 }

 TCanvas *canv_sigma=new TCanvas("sigma of pedestal fits for MWPCs","sigma of pedestal fits for MWPCs",1200,900);
 canv_sigma->Divide(4,3);
 canv_sigma->cd(1);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC2XL[i]->SetMinimum(0);
   hist_sigmaC2XL[i]->SetMaximum(100);
   hist_sigmaC2XL[i]->SetLineColor(i+2);
   hist_sigmaC2XL[i]->SetMarkerColor(i+2);
   hist_sigmaC2XL[i]->Draw();
  }
  else{
   hist_sigmaC2XL[i]->SetLineColor(i+2);
   hist_sigmaC2XL[i]->SetMarkerColor(i+2);
   hist_sigmaC2XL[i]->Draw("same");
  }
 }
 legend->Draw();

 canv_sigma->cd(2);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC2XR[i]->SetMinimum(0);
   hist_sigmaC2XR[i]->SetMaximum(100);
   hist_sigmaC2XR[i]->SetLineColor(i+2);
   hist_sigmaC2XR[i]->SetMarkerColor(i+2);
   hist_sigmaC2XR[i]->Draw();
  }
  else{
   hist_sigmaC2XR[i]->SetLineColor(i+2);
   hist_sigmaC2XR[i]->SetMarkerColor(i+2);
   hist_sigmaC2XR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(3);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC2YL[i]->SetMinimum(0);
   hist_sigmaC2YL[i]->SetMaximum(100);
   hist_sigmaC2YL[i]->SetLineColor(i+2);
   hist_sigmaC2YL[i]->SetMarkerColor(i+2);
   hist_sigmaC2YL[i]->Draw();
  }
  else{
   hist_sigmaC2YL[i]->SetLineColor(i+2);
   hist_sigmaC2YL[i]->SetMarkerColor(i+2);
   hist_sigmaC2YL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(4);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC2YR[i]->SetMinimum(0);
   hist_sigmaC2YR[i]->SetMaximum(100);
   hist_sigmaC2YR[i]->SetLineColor(i+2);
   hist_sigmaC2YR[i]->SetMarkerColor(i+2);
   hist_sigmaC2YR[i]->Draw();
  }
  else{
   hist_sigmaC2YR[i]->SetLineColor(i+2);
   hist_sigmaC2YR[i]->SetMarkerColor(i+2);
   hist_sigmaC2YR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(5);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC3XL[i]->SetMinimum(0);
   hist_sigmaC3XL[i]->SetMaximum(100);
   hist_sigmaC3XL[i]->SetLineColor(i+2);
   hist_sigmaC3XL[i]->SetMarkerColor(i+2);
   hist_sigmaC3XL[i]->Draw();
  }
  else{
   hist_sigmaC3XL[i]->SetLineColor(i+2);
   hist_sigmaC3XL[i]->SetMarkerColor(i+2);
   hist_sigmaC3XL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(6);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC3XR[i]->SetMinimum(0);
   hist_sigmaC3XR[i]->SetMaximum(100);
   hist_sigmaC3XR[i]->SetLineColor(i+2);
   hist_sigmaC3XR[i]->SetMarkerColor(i+2);
   hist_sigmaC3XR[i]->Draw();
  }
  else{
   hist_sigmaC3XR[i]->SetLineColor(i+2);
   hist_sigmaC3XR[i]->SetMarkerColor(i+2);
   hist_sigmaC3XR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(7);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC3YL[i]->SetMinimum(0);
   hist_sigmaC3YL[i]->SetMaximum(100);
   hist_sigmaC3YL[i]->SetLineColor(i+2);
   hist_sigmaC3YL[i]->SetMarkerColor(i+2);
   hist_sigmaC3YL[i]->Draw();
  }
  else{
   hist_sigmaC3YL[i]->SetLineColor(i+2);
   hist_sigmaC3YL[i]->SetMarkerColor(i+2);
   hist_sigmaC3YL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(8);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC3YR[i]->SetMinimum(0);
   hist_sigmaC3YR[i]->SetMaximum(100);
   hist_sigmaC3YR[i]->SetLineColor(i+2);
   hist_sigmaC3YR[i]->SetMarkerColor(i+2);
   hist_sigmaC3YR[i]->Draw();
  }
  else{
   hist_sigmaC3YR[i]->SetLineColor(i+2);
   hist_sigmaC3YR[i]->SetMarkerColor(i+2);
   hist_sigmaC3YR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(9);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC4XL[i]->SetMinimum(0);
   hist_sigmaC4XL[i]->SetMaximum(100);
   hist_sigmaC4XL[i]->SetLineColor(i+2);
   hist_sigmaC4XL[i]->SetMarkerColor(i+2);
   hist_sigmaC4XL[i]->Draw();
  }
  else{
   hist_sigmaC4XL[i]->SetLineColor(i+2);
   hist_sigmaC4XL[i]->SetMarkerColor(i+2);
   hist_sigmaC4XL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(10);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC4XR[i]->SetMinimum(0);
   hist_sigmaC4XR[i]->SetMaximum(100);
   hist_sigmaC4XR[i]->SetLineColor(i+2);
   hist_sigmaC4XR[i]->SetMarkerColor(i+2);
   hist_sigmaC4XR[i]->Draw();
  }
  else{
   hist_sigmaC4XR[i]->SetLineColor(i+2);
   hist_sigmaC4XR[i]->SetMarkerColor(i+2);
   hist_sigmaC4XR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(11);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC4YL[i]->SetMinimum(0);
   hist_sigmaC4YL[i]->SetMaximum(100);
   hist_sigmaC4YL[i]->SetLineColor(i+2);
   hist_sigmaC4YL[i]->SetMarkerColor(i+2);
   hist_sigmaC4YL[i]->Draw();
  }
  else{
   hist_sigmaC4YL[i]->SetLineColor(i+2);
   hist_sigmaC4YL[i]->SetMarkerColor(i+2);
   hist_sigmaC4YL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_sigma->cd(12);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_sigmaC4YR[i]->SetMinimum(0);
   hist_sigmaC4YR[i]->SetMaximum(100);
   hist_sigmaC4YR[i]->SetLineColor(i+2);
   hist_sigmaC4YR[i]->SetMarkerColor(i+2);
   hist_sigmaC4YR[i]->Draw();
  }
  else{
   hist_sigmaC4YR[i]->SetLineColor(i+2);
   hist_sigmaC4YR[i]->SetMarkerColor(i+2);
   hist_sigmaC4YR[i]->Draw("same");
  }
 }
 //legend->Draw();
 canv_sigma->SaveAs("sigma vs strip.pdf");
}

