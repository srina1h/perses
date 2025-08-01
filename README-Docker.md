# Perses Differential Testing Docker Setup

This Docker setup allows you to run Perses differential testing for JavaScript engines in a containerized environment.

## Prerequisites

- Docker and Docker Compose installed on your system
- At least 20GB of available RAM (16GB for JVM + 4GB for system)
- At least 8 CPU cores recommended
- 50GB+ of available disk space

## Quick Start

### 1. Build and Run with Docker Compose (Recommended)

```bash
# Create necessary directories
mkdir -p results logs custom-seeds

# Build and start the container
docker-compose up -d

# View logs
docker-compose logs -f

# Stop the container
docker-compose down
```

### 2. Manual Docker Commands

```bash
# Build the image
docker build -t perses-differential-testing .

# Run with volume mounts
docker run -d \
  --name perses-differential-testing \
  --memory=20g \
  --cpus=8 \
  -v $(pwd)/results:/workspace/kitten/temp_testing_campaigns \
  -v $(pwd)/logs:/workspace/logs \
  -v $(pwd)/custom-seeds:/workspace/kitten/scripts/javascript/seeds:ro \
  perses-differential-testing

# View logs
docker logs -f perses-differential-testing

# Stop and remove container
docker stop perses-differential-testing
docker rm perses-differential-testing
```

## Directory Structure

```
.
├── Dockerfile                    # Docker image definition
├── docker-compose.yml           # Docker Compose configuration
├── results/                     # Mounted volume for test results
│   ├── differential_finding_folder_javascript/
│   ├── differential_processing_folder_javascript/
│   └── differential_duplicate_folder_javascript/
├── logs/                        # Mounted volume for logs
└── custom-seeds/                # Optional: Custom JavaScript seeds
```

## Configuration

### Memory and CPU Settings

The default configuration uses:
- **Memory**: 20GB total (16GB for JVM, 4GB for system)
- **CPU**: 8 cores
- **JVM Options**: `-Xmx16G -Xms4G`

To adjust these settings:

1. **For Docker Compose**: Edit `docker-compose.yml` and modify the `deploy.resources` section
2. **For manual Docker**: Use `--memory` and `--cpus` flags

### JavaScript Engines

The container includes the following JavaScript engines:
- **V8**: Google's V8 JavaScript engine
- **Hermes**: Facebook's Hermes JavaScript engine
- **GraalJS**: Oracle's GraalJS engine
- **JavaScriptCore**: Apple's JavaScriptCore engine

All engines are installed via JSVU (JavaScript Version Updater) and are automatically configured.

## Monitoring and Results

### Viewing Logs

```bash
# Real-time logs
docker-compose logs -f

# Or for manual Docker
docker logs -f perses-differential-testing
```

### Accessing Results

Results are automatically saved to the `./results` directory on your host system:

- **Differential Findings**: `./results/differential_finding_folder_javascript/`
- **Processing Data**: `./results/differential_processing_folder_javascript/`
- **Duplicate Detection**: `./results/differential_duplicate_folder_javascript/`

### Interactive Access

To access the container interactively:

```bash
# With Docker Compose
docker-compose exec perses-differential-testing bash

# With manual Docker
docker exec -it perses-differential-testing bash
```

## Customization

### Adding Custom Seeds

1. Place your JavaScript seed files in the `./custom-seeds/` directory
2. The container will use these seeds instead of the default ones

### Modifying Configuration

To modify the differential testing configuration:

1. Access the container interactively
2. Edit `/workspace/kitten/scripts/javascript/differential-testing-config.yaml`
3. Restart the container

### Environment Variables

You can set environment variables in `docker-compose.yml`:

```yaml
environment:
  - JAVA_OPTS=-Xmx32G -Xms8G  # Increase memory for larger workloads
  - THREADS=10                # Increase thread count
```

## Troubleshooting

### Common Issues

1. **Out of Memory Errors**
   - Increase the memory limit in Docker
   - Reduce JVM heap size in `JAVA_OPTS`

2. **Build Failures**
   - Ensure you have sufficient disk space
   - Check internet connectivity for dependencies

3. **Engine Not Found**
   - Verify JSVU installation in the container
   - Check engine paths in the configuration

### Debugging

```bash
# Check container status
docker ps -a

# View detailed logs
docker logs perses-differential-testing

# Access container for debugging
docker exec -it perses-differential-testing bash

# Check available JavaScript engines
docker exec perses-differential-testing ls -la /usr/local/bin/js-engines/
```

## Performance Optimization

### For High-Performance Systems

1. **Increase Resources**:
   ```yaml
   deploy:
     resources:
       limits:
         memory: 64G
         cpus: '16'
   ```

2. **Optimize JVM Settings**:
   ```yaml
   environment:
     - JAVA_OPTS=-Xmx48G -Xms16G -XX:+UseG1GC -XX:MaxGCPauseMillis=200
   ```

3. **Use SSD Storage**: Mount volumes on SSD for better I/O performance

### For Resource-Constrained Systems

1. **Reduce Memory Usage**:
   ```yaml
   deploy:
     resources:
       limits:
         memory: 8G
         cpus: '4'
   ```

2. **Adjust JVM Settings**:
   ```yaml
   environment:
     - JAVA_OPTS=-Xmx6G -Xms2G
   ```

## Security Considerations

- The container runs as root (required for Bazel builds)
- Consider running in a dedicated environment
- Review the mounted volumes for sensitive data
- Use read-only mounts where possible

## Support

For issues related to:
- **Perses**: Check the [Perses repository](https://github.com/perses-project/perses)
- **Docker Setup**: Review this README and Docker documentation
- **JavaScript Engines**: Check JSVU documentation 