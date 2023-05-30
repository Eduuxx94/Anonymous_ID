module com.example.anonymous_id {
    requires javafx.controls;
    requires javafx.fxml;

    requires com.dlsc.formsfx;

    opens com.example.anonymous_id to javafx.fxml;
    exports com.example.anonymous_id;
}