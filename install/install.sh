if [ -f "/usr/bin/rle" ]; then
    echo "Removing last program"
    sudo rm /usr/bin/rle
fi

echo "cp ../build/rle /usr/bin"
sudo cp ../build/rle /usr/bin
