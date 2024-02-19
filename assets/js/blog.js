function togglePost(element) {
    var content = element.nextElementSibling;
    if (content.style.display === "block") {
        content.style.display = "none";
        element.querySelector(".arrow").style.transform = "rotate(0deg)";
    } else {
        content.style.display = "block";
        element.querySelector(".arrow").style.transform = "rotate(90deg)";
    }
}