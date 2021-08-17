<?php

        $id = $_GET["id"];
        $v = $_GET["v"];
        $v2 = $_GET["v2"];

        $timestamp = time();
        $entry = $timestamp.",".$v.",".$v2."\n";

        file_put_contents("logs/".$id.".txt", $entry, FILE_APPEND);


?>