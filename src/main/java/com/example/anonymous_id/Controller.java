package com.example.anonymous_id;

import javafx.fxml.FXML;
import javafx.stage.FileChooser;
import javafx.scene.control.Alert;

import java.io.File;
import java.io.*;
import javafx.scene.control.ProgressBar;

public class Controller {
    @FXML
    private ProgressBar progressBar;

    @FXML
    private void onOpenFileButtonClick() {
        FileChooser fileChooser = new FileChooser();
        File selectedFile = fileChooser.showOpenDialog(null);

        if (selectedFile != null) {
            try {
                BufferedReader reader = new BufferedReader(new FileReader(selectedFile));
                StringBuilder stringBuilder = new StringBuilder();

                long fileSize = selectedFile.length();
                long bytesRead = 0;

                String line;
                while ((line = reader.readLine()) != null) {
                    if (line.contains("<CustomerID>") || line.contains("<CustomerTaxID>")) {
                        line = line.replaceAll("\\d", "*"); // Replace all numbers with 9
                    }
                    stringBuilder.append(line).append("\n");

                    // Update progress
                    bytesRead += line.getBytes().length;
                    double progress = (double) bytesRead / fileSize;
                    progressBar.setProgress(progress);
                }
                reader.close();

                String modifiedContent = stringBuilder.toString();

                // Save a copy of the modified file
                File outputFile = new File(selectedFile.getParent(), "anonimizado_" + selectedFile.getName());
                BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
                writer.write(modifiedContent);
                writer.close();

                // Show popup message after file is saved
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Arquivo salvo\n");
                alert.setHeaderText("Arquivo salvo com sucesso.");
                alert.setContentText("Arquivo modificado salvo em:\n" + outputFile.getAbsolutePath());
                alert.showAndWait();

                System.out.println("Arquivo modificado salvo em: " + outputFile.getAbsolutePath());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}