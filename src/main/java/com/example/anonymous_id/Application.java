package com.example.anonymous_id;

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Objects;

public class Application extends javafx.application.Application {

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(Application.class.getResource("hello-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 300, 300);
        stage.getIcons().add(new Image(Objects.requireNonNull(Application.class.getResourceAsStream("/com/example/Image/Logotipo-PR_vert_cor.png"))));
        stage.setTitle("Anonymous ID");
        stage.setResizable(false); // Prevent window resizing
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}